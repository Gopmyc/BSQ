/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:29:29 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 18:00:21 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/* Recup les caracteristiques de la map :  
taille de la map, le caractere vide,
le caractere obstacle et le caractere plein */
struct s_map	ft_set_map(struct s_map ref, char *content)
{
	char	size[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (content[i])
	{
		if (ft_is_int(content[i]))
			size[j++] = content[i];
		if (i > 0 && ft_is_int(content[i - 1]) && !ft_is_int(content[i]))
			break ;
		i++;
	}
	size[j] = '\0';
	ref.size = ft_str_to_int(size);
	ref.empty = content[i];
	ref.char_obs = content[i + 1];
	ref.char_full = content[i + 2];
	return (ref);
}

/* Cree l'allocation dynamique pour faire le tableau de resolution */
int	**ft_allocate_map(int size)
{
	int	**array;
	int	i;
	int	j;

	array = (int **)malloc(size * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = (int *)malloc(size * sizeof(int));
		if (!array[i])
		{
			j = 0;
			while (j < i)
				free(array[j++]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

/* remplir le tableau en fonction de si c'est un caracter vide ou non (1 ou 0)*/
void	ft_fill_map(int **array, struct s_map ref, char *content)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < ref.size)
	{
		j = 0;
		while (j < ref.size)
		{
			if (content[k] == ref.empty)
				array[i][j] = 1;
			else if (content[k] == ref.char_obs)
				array[i][j] = 0;
			else
				array[i][j] = 0;
			j++;
			k++;
		}
		k++;
		i++;
	}
}

/* Regroupement de la fonction ft_allocate_map et de la fonction ft_fill_map*/
int	**ft_get_resolve_map(struct s_map ref, char *content)
{
	int	**array;

	array = ft_allocate_map(ref.size);
	if (!array)
		return (NULL);
	ft_fill_map(array, ref, content);
	return (array);
}

/* Fonction pour tester si le carre peut s'agrandir ou non */
struct s_resolve	ft_resolve_array(int size, int **array,
						struct s_resolve resolve)
{
	int	i;
	int	j;

	j = 1;
	while (j < size)
	{
		i = 1;
		while (i < size)
		{
			if (array[j][i] != 0)
				array[j][i] = ft_min3(array[j - 1][i],
						array[j][i - 1], array[j - 1][i - 1]) + 1;
			if (array[j][i] > resolve.max)
			{
				resolve.x = array[j - 1][i];
				resolve.y = array[j][i - 1];
				resolve.max = array[j][i];
			}
			i++;
		}
		j++;
	}
}
