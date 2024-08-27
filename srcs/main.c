/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:03:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 17:57:55 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char **argv)
{
	struct s_resolve	resolve;
	struct s_map		ref;
	char				*map;
	int					**array;

	(void)argc;
	(void)argv;
	resolve.x = 0;
	resolve.y = 0;
	resolve.max = 0;
	map = ft_file_content("bsq.txt");
	if (!(map))
		return (1);
	ref = ft_set_map(ref, map);
	array = ft_get_resolve_map(ref, map);
	ft_resolve_array(ref.size, array, resolve);
	ft_print_array(ref.size, array);
	return (0);
}
