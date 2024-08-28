/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:14:42 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/28 21:15:55 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_int(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int long	ft_size_file(char *path)
{
	int long	size;
	int			file;
	char		element;

	file = open(path, O_RDONLY);
	size = 0;
	if (file == -1)
		return (0);
	while (read(file, &element, 1) > 0)
	{
		size++;
	}
	return (size);
}

int	ft_str_to_int(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
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
