/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:14:12 by rmount            #+#    #+#             */
/*   Updated: 2023/04/25 16:20:11 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_image(t_game *hhs)//directing to xpm files that can be converted to new image instances
{
	int	x;
	int	y;

    printf("About to do the images\n");
	hhs->slime = mlx_xpm_file_to_image(hhs->mlx, "images/slime2.xpm", &x, &y);
	hhs->floor = mlx_xpm_file_to_image(hhs->mlx, "images/ground.xpm", &x, &y);
	hhs->snail = mlx_xpm_file_to_image(hhs->mlx, "images/snail.xpm", &x, &y);
	hhs->wall = mlx_xpm_file_to_image(hhs->mlx, "images/wall.xpm", &x, &y);
	hhs->exit = mlx_xpm_file_to_image(hhs->mlx, "images/exit.xpm", &x, &y);
    printf("We did the images!\n");
}

void	put_slime(t_game *hhs, int h, int w)
{
	mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->slime, w * 100, h * 100);
	hhs->locationh = h;//remembering that the picker needs to move according to button commands
	hhs->locationw = w;
}

void	snail_count(t_game *hhs, int h, int w)
{
	mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->snail, w * 100, h * 100);
	hhs->snails++;
}

void	put_image(t_game *hhs)//put the images into the window as dictated by the map
{
	int	w;
	int	h;

	h = 0;
	hhs->snails = 0;
	while (h < hhs->map_h)//as long as we're not outside the height of the map
	{
		w = 0;
		while (hhs->map[h][w])//as long as we're still on the map
		{
			mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->floor, w * 100, h * 100);
			if (hhs->map[h][w] == '1')
				mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->wall, w * 100, h * 100);
			if (hhs->map[h][w] == 'C')
				snail_count(hhs, h, w);
			if (hhs->map[h][w] == 'E')
				mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->exit, w * 100, h * 100);
			if (hhs->map[h][w] == 'P')
				put_slime(hhs, h, w);
			w++;
		}
		h++;
	}
}
