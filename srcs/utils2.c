/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:08:29 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 18:50:23 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_min3(int a, int b, int c)
{
	int	min_ab;

	if (a < b)
	{
		min_ab = a;
	}
	else
	{
		min_ab = b;
	}
	if (min_ab < c)
	{
		return (min_ab);
	}
	else
	{
		return (c);
	}
}

void	ft_del_char(char *str, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || y < 0 || x > y)
		return ;
	i = 0;
	while (str[i] != '\0' && i <= y)
	{
		if (i == x)
		{
			j = i;
			while (str[j + (y - x + 1)] != '\0')
			{
				str[j] = str[j + (y - x + 1)];
				j++;
			}
			str[j] = '\0';
			break ;
		}
		i++;
	}
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
