/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:14:42 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/26 15:57:34 by ghoyaux          ###   ########.fr       */
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

