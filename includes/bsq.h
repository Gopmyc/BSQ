/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:02:27 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/26 16:38:29 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct s_map
{
	int long	size;
	char		*empty;
	char		char_obs;
	char		char_full;
};

/* Decalaration of utils.c functions */
int			ft_strlen(char *str);
int long	ft_size_file(char *path);

/* Decalaration of utils2.c functions */
int			is_separator(char c, char *charset);
int			count_words(char *str, char *charset);
char		*ft_strndup(char *start, int len);
char		**ft_split(char *str, char *charset);

/* decalaration of base.c functions */
int long	ft_map_size(char *path);
char		*ft_get_empty_characters(char *path);

/* [1] --> Lire le fichier passer en input et
	le transformer en chaine de caractere */
/* [2] --> recuperer la taille de la map, le caractere vide,
	le caractere obstacle et le caractere plein et stocker tous
	cella dans la structure s_map */
// [3] --> Faire l'algo de resolution
// [4] --> faire le truc de l'entre standard