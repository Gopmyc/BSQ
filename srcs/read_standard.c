/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:22:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/28 20:56:20 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*ft_standard_content(void)
{
	char		*map;
	int			i;
	char		element;
	ssize_t		bytes_read;

	map = (char *)malloc((1024 + 1) * sizeof(char));
	if (!map)
		return (NULL);
	i = 0;
	bytes_read = read(0, &element, 1);
	while (bytes_read > 0)
	{
		if (i >= 1024)
			break ;
		map[i] = element;
		i++;
		bytes_read = read(0, &element, 1);
	}
	if (bytes_read == -1)
	{
		free(map);
		return (NULL);
	}
	map[i] = '\0';
	return (map);
}
