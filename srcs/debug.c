/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:35:33 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 20:52:59 by ghoyaux          ###   ########.fr       */
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

void	ft_print_array_clean(int size, int	**array, struct s_resolve resolve)
{
	char	c;
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (array[j][i] != 0 && array[j][i] < resolve.max)
			{
				write(1, "1", 1);
				write(1, ", ", 2);
			}
			else
			{
				c = array[j][i] + '0';
				write(1, &c, 1);
				write(1, ", ", 2);
			}
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
