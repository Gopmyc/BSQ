/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:09:55 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/28 19:03:42 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_free_map(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_str_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && !(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(char *map, struct s_map ref)
{
	if (!(ft_check_line_map(map)))
		return (0);
	if (!(all_line_valid(map, ref)))
		return (0);
	if (ref.empty == ref.char_obs || ref.empty == ref.char_full
		|| ref.char_obs == ref.char_full)
		return (0);
	if (!(ft_str_valid(map)))
		return (0);
	return (1);
}

void	ft_error_message(int code)
{
	if (code == 1)
		write(1, "map error\n", (11 * sizeof(char)));
	if (code == 2)
		write(1, "\n", (2 * sizeof(char)));
}
