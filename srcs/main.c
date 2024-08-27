/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:03:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 19:27:41 by ghoyaux          ###   ########.fr       */
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
	map = ft_file_content("bsq.txt");
	if (!(map))
		return (1);
	ref = ft_set_map(ref, map);
	array = ft_get_resolve_map(ref, map);
	resolve = ft_resolve_array(ref.size, array, resolve);
	ft_write_resolve(ref.size, array, resolve, ref);
	return (0);
}
