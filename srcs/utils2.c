/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:08:29 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/08/27 18:08:31 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_min3(int a, int b, int c)
{
	int	min_ab;

	if (a < b)
	{
		min_ab = a;
	}
	else
	{
		min_ab = b;
	}
	if (min_ab < c)
	{
		return (min_ab);
	}
	else
	{
		return (c);
	}
}
