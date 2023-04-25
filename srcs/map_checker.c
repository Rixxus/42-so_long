/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:10:19 by rmount            #+#    #+#             */
/*   Updated: 2023/04/25 17:03:06 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//start at map_check function

void	wall_check(t_game *hhs)//checking that border of map is made up of walls
{
	int	h;
	int	w;

	w = 0;
	while (w < hhs->map_w)
	{
		if (!(hhs->map[0][w] == '1' && hhs->map[hhs->map_h - 1][w] == '1'))
		{
			ft_printf("\exit[31m\exit[1mError\nOops, your map is missing bushes\exit[0m \n");
			exit_game(hhs);
		}
		w++;
	}
	h = 0;
	while (h < hhs->map_h)
	{
		if (!(hhs->map[h][0] == '1' && hhs->map[h][hhs->map_w - 1] == '1'))
		{
			ft_printf("\exit[31m\exit[1mError\nOops, your map is missing bushes\exit[0m \n");
			exit_game(hhs);
		}
		h++;
	}
}

void	count_cpe(t_game *hhs, int w, int h) //keep track to ensure correct amount of each element is present in map
{
	if (hhs->map[h][w] == 'C')
		hhs->c_count++;
	if (hhs->map[h][w] == 'P')
		hhs->p_count++;
	if (hhs->map[h][w] == 'E')
		hhs->e_count++;
}

void	only_10ecp(t_game *hhs) //checking one element at a time, ensure that only the allowed chars are used in the map
{
	int	w;
	int	h;

	h = 0;
	while (h < hhs->map_h - 1)
	{
		w = 0;
		while (w <= hhs->map_w)
		{	
			count_cpe(hhs, w, h);
			if (hhs->map[h][w] != '1' && hhs->map[h][w] != '0'
				&& hhs->map[h][w] != 'P'
				&& hhs->map[h][w] != 'E' && hhs->map[h][w] != 'C'
				&& hhs->map[h][w] != '\n')
			{
				ft_printf("\exit[31m\exit[1mError\nHm seems there's an unknown char\exit[0m \n");
				exit_game(hhs);
			}
			w++;
		}
		h++;
	}
}

void	map_check(t_game *hhs)
{
	wall_check(hhs);
	only_10ecp(hhs);
	if (!(hhs->c_count > 1 && hhs->p_count == 1 && hhs->e_count == 1))
	{
		ft_printf("\exit[31m\exit[1mError\nNeed 1 picker & exit and >1 strawberry\exit[0m \n");
		exit_game(hhs);
	}
}