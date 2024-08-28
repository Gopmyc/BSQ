/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:03:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/28 21:30:25 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	process_map(char *map, struct s_map ref)
{
	int					**array;
	struct s_resolve	resolve;

	array = ft_get_resolve_map(ref, map);
	resolve = ft_resolve_array(ref.size, array, (struct s_resolve){0});
	ft_write_resolve(ref.size, array, resolve, ref);
	free(map);
	ft_free_map(array, ref.size);
	return (1);
}

int	main(int argc, char **argv)
{
	int				i;
	struct s_map	ref;
	char			*map;

	if (argc < 2)
	{
		map = ft_standard_content();
		if (!map)
			return (1);
		ref = ft_set_map((struct s_map){0}, map);
		return (process_map(map, ref));
	}
	i = 1;
	while (i < argc)
	{
		map = ft_file_content(argv[i]);
		if (!map)
			return (1);
		ref = ft_set_map((struct s_map){0}, map);
		process_map(map, ref);
		i++;
	}
	return (0);
}
