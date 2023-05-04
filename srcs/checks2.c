/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:21:53 by rmount            #+#    #+#             */
/*   Updated: 2023/05/04 15:19:10 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function reads a supplied string (the argument supplied to the program)
	and tests whether the last four characters are .ber.
*/
int	check_map_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i-1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
	{
		close_program("Map must be a .ber file\n");
		return (1);
	}
	return (0);
}

/*
	This function is called by valid_path().
	It modifies the map copy, essentially changing
	all non-1 chars to Ps and counting the number
	of Es and Cs encountered.
*/

static void	flood_fill(t_game *game, int paint, int y, int x)
{
	if (game->map_copy[y][x] == '1')
		return ;
	else if (game->map_copy[y][x] == 'C')
	{
		game->cpy_c_count++;
		game->map_copy[y][x] = '0';
	}
	else if (game->map_copy[y][x] == 'E')
	{
		game->cpy_e_count++;
		game->map_copy[y][x] = '0';
	}
	if (game->map_copy[y][x] == '0')
	{
		game->map_copy[y][x] = paint;
		flood_fill(game, paint, y, x + 1);
		flood_fill(game, paint, y, x - 1);
		flood_fill(game, paint, y + 1, x);
		flood_fill(game, paint, y - 1, x);
	}
}

/*
	This function checks there is a valid path to the
	exit and all collectables by making a copy 
	of the map and passing it to flood_fill().
	Because this function cannot get passed 1s if, 
	at the end of all of flood_fill,
	the e_count and c_count do not match the 
	e_count and c_count of the original map, it means
	the map is not solveable, either because the 
	exit is inaccessible, or because one or more 
	collectables are inaccessible.
*/

void	valid_path(t_game *hhs, int y, int x)
{
	hhs->map_copy = malloc(sizeof(char *) * (hhs->w + 1));
	copy_map(hhs->map_copy, hhs->map);
	hhs->map_copy[y][x] = '0';
	flood_fill(hhs, 'P', y, x);
	if (hhs->c_count != hhs->cpy_c_count)
	{
		close_program("Map cannot be solved, path is not valid\n");
	}
	if (hhs->e_count != hhs->cpy_e_count)
	{
		close_program("Map cannot be solved, path is not valid\n");
	}
}

/*
	This function runs a number of checks on the map
	to ensure it is valid.
	- It begins by finding and assigning the player's
	position to hhs->playerx and hhs->playery.
	- Calls check_walls
	- Calls valid_count
	- Calls valid_path passing the player's location.
	If all checks are passed successfull, returns 0 to main.
*/

void	valid_map(t_game *hhs)
{
	int	x;
	int	y;

	y = 0;
	while (hhs->map[y] != NULL)
	{
		x = 0;
		while (hhs->map[y][x] != '\0')
		{
			if (hhs->map[y][x] == 'P')
			{
				hhs->playerx = x;
				hhs->playery = y;
			}
			x++;
		}
		y++;
	}
	check_walls(hhs);
	valid_count(hhs);
	valid_path(hhs, hhs->playery, hhs->playerx);
}
