/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:02:27 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 19:13:49 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct s_resolve
{
	int	x;
	int	y;
	int	max;
};

struct s_map
{
	int long	size;
	char		empty;
	char		char_obs;
	char		char_full;
};

/* Declaration of debug.c functions [temporary things]*/
void				ft_print_array(int size, int	**array);

/* Decalaration of utils.c functions */
int					ft_strlen(char *str);
int					ft_is_int(char c);
int long			ft_size_file(char *path);
int					ft_str_to_int(char *str);
char				*ft_file_content(char *path);

/* Decalaration of utils2.c functions */
int					ft_min3(int a, int b, int c);
void				ft_del_char(char *str, int x, int y);
int					**ft_allocate_map(int size);

/* decalaration of base.c functions */
struct s_map		ft_set_map(struct s_map ref, char *content);
void				ft_fill_map(int **array, struct s_map ref, char *content);
int					**ft_get_resolve_map(struct s_map ref, char *content);
struct s_resolve	ft_resolve_array(int size, int **array,
						struct s_resolve resolve);
void				ft_write_resolve(int size, int **array,
						struct s_resolve resolve, struct s_map ref);

/* Declaration of base.c functions */
int long			ft_map_size(char *path);
char				*ft_file_content(char *path);
char				ft_get_empty_characters(char *content);

/* [1] --> Lire le fichier passer en input et
	le transformer en chaine de caractere */
// ...
// [4] --> faire le truc de l'entre standard