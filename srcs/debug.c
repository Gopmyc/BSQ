/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:35:33 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/26 21:55:08 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_print_array(int size, int	**array)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			c = array[i][j] + '0';
			write(1, &c, sizeof(char));
			write(1, ", ", (3 * sizeof(char)));
			i++;
		}
		write(1, "\n", sizeof(char));
		j++;
	}
}
