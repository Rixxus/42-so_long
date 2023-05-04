/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:46:19 by rmount            #+#    #+#             */
/*   Updated: 2023/05/04 20:57:43 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function is called by draw_map. It calls the
	mlx_put_image_to_window function to put the slime (the player) at the 
	supplied coordinates.
*/

void	place_slime(t_game *hhs, int height, int width)
{
	mlx_put_image_to_window(hhs->mlx, hhs->win, hhs->slime,
		width * 50, height * 50);
}

/*
	This function iterates through the map, calling the 
	mlx_put_image_to_window function where a collectable
	(snail) is found on the map.
*/

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

/*
	This function calls the mlx_xpm_file_to_image function, 
	which converts the xpm files (the tile artwork) to new image 
	instances which are assigned to the variables tree, ground, slime, 
	snail and burrow for later use.
	The x and y we are passing here are unassigned as we are
	going to tell the images what width and height to be later,
	but the function requires an input to not be sad.
*/

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

/*
	This function iterates through the map calling the 
	mlx_put_image_to_window function to put a particular image to the 
	window at the current location depending on the corresponding symbol 
	on the map file. 
	The first call places the ground image on every space (so that we 
	see ground tiles behind snails, the exit and player), and then puts
	another image on top if it is a wall, slime or exit.
	Finally we call the place_snail function for the collectables. 
	place_slime and place_snail have been done as separate functions to
	meet the norminette's max 25 line function rule.
*/

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
