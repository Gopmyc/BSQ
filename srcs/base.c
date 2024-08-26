/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:29:29 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/26 16:22:06 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/* Pour la size de la structure */
int long	ft_map_size(char *path)
{
	int long	size;
	int			i;
	int			file;
	char		element;

	i = 0;
	size = 0;
	file = open(path, O_RDONLY);
	i = 0;
	if (file == -1)
		return (0);
	while (read(file, &element, 1) > 0)
	{
		if (element == '\n')
			size++;
		i++;
	}
	return (size--);
}

/* recupere le contenue du fichier en une chaine de
	caractere (pour travailler plus facilement 
	dessus et eviter les apelle repetitif au read* 
*/
char	*ft_file_content(char *path)
{
	char		*map;
	int			size;
	int			file;
	int			i;
	char		element;

	size = ft_size_file(path);
	map = (char *)malloc((size + 1) * sizeof(char));
	if (!(map))
		return (NULL);
	file = open(path, O_RDONLY);
	i = 0;
	if (file == -1)
		return (0);
	while (read(file, &element, 1) > 0)
	{
		map[i] = element;
		i++;
	}
	map[i] = '\0';
	return (map);
}

/* Recup le caractere vide de la map d*/
char	ft_get_empty_characters(char *content)
{
	char		c;
	int			i;

	i = 0;
	while (content[i])
	{
		if (ft_is_int(content[i - 1]) && (!(ft_is_int(content[i]))))
		{
			c = content[i];
			break ;
		}
		i++;
	}
	return (c);
}

