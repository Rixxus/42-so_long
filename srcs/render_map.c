/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:22 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 14:27:24 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_slime(t_game *hhs, int height, int width)
{
	mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->slime,
		width * 50, height * 50);
	hhs->playery = height;
	hhs->playerx = width;
}

void	place_snail(t_game *hhs)
{
	int	height;
	int	width;

	height = 0;
	while (hhs->map[height])
	{
		width = 0;
		while (hhs->map[height][width])
		{
			if (hhs->map[height][width] == 'C')
				mlx_put_image_to_window(hhs->mlx, hhs->win,
					hhs->snail, width * 50, height * 50);
			width++;
		}
		height++;
	}
}

void	assign_images(t_game *hhs)
{
	int	x;
	int	y;

	hhs->tree = mlx_xpm_file_to_image(hhs->mlx,
			"images/tree50.xpm", &x, &y);
	hhs->ground = mlx_xpm_file_to_image(hhs->mlx,
			"images/forestground50.xpm", &x, &y);
	hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
			"images/slime150.xpm", &x, &y);
	hhs->snail = mlx_xpm_file_to_image(hhs->mlx,
			"images/snail50.xpm", &x, &y);
	hhs->burrow = mlx_xpm_file_to_image(hhs->mlx,
			"images/burrow50.xpm", &x, &y);
}

void	draw_map(t_game *hhs)
{
	int		height;
	int		width;

	height = 0;
	while (hhs->map[height])
	{
		width = 0;
		while (hhs->map[height][width])
		{
			mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->ground,
				width * 50, height * 50);
			if (hhs->map[height][width] == '1')
				mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->tree,
					width * 50, height * 50);
			if (hhs->map[height][width] == 'P')
				place_slime(hhs, height, width);
			if (hhs->map[height][width] == 'E')
				mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->burrow,
					width * 50, height * 50);
			width++;
		}
		height++;
		place_snail(hhs);
	}
}

/*
	This function takes the pointer to the game map,
	and a pointer to the copy map, and copies the 
	characters from the game map to the copy.
	It is called by valid_path().
*/
void	copy_map(char **origin_map, char **copy_map)
{
	int	i;

	i = 0;
	while (copy_map[i])
	{
		origin_map[i] = ft_strdup(copy_map[i]);
		i++;
	}
	origin_map[i] = NULL;
}
