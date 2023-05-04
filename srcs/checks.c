/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:22:13 by rmount            #+#    #+#             */
/*   Updated: 2023/05/04 20:48:17 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function checks that the supplied map is a rectangle by measuring the
	length of the first row and checking that all other rows are the same size.
	It also then checks if the height is the same as the width. If either of 
	these conditions fail the program closes with an error message.
*/
static void	valid_shape(t_game *hhs)
{
	int	row_num;
	int	first_row_length;
	int	current_row_length;

	row_num = 0;
	first_row_length = ft_strlen(hhs->map[0]);
	while (hhs->map[row_num] != 0)
	{
		current_row_length = ft_strlen(hhs->map[row_num]);
		if (current_row_length != first_row_length)
		{
			close_program("Rows aren't all the same length. Not a rectangle.\n");
		}
		row_num++;
	}
	if (row_num == first_row_length - 1)
	{
		close_program("This is a square, not a rectangle.\n");
	}
}

/*
	This function iterates through each row in two different
	while loop. 
	The first checks if any map piece on the top
	or bottom row isn't a 1, and closes with the error 
	message if this is true.
	The second checks if any map piece on the left or the
	right columns isn't 1, and closes with the error message
	if this is true.
*/

void	check_walls(t_game *hhs)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	valid_shape(hhs);
	while (hhs->map[y][x + 1])
	{
		if (hhs->map[y][x] != '1' || hhs->map[hhs->h - 1][x] != '1')
		{
			close_program("Missing wall/s on the top or bottom.\n");
		}
		x++;
	}
	while (hhs->map[y])
	{
		if (hhs->map[y][0] != '1' || hhs->map[y][hhs->w - 1] != '1')
		{
			close_program("Missing wall/s on the left or right.\n");
		}
		y++;
	}
}

/*
	Looks at the map tile at coordinates x and y and increments the total number 
	of each tile type.
	If a tile is found that doesn't match the accepted 
	characters (E, C, P, 1 & 0), the program closes with
	the error message.
*/
static void	item_count(t_game *hhs, int y, int x)
{
	if (hhs->map[y][x] == 'E')
		hhs->e_count++;
	if (hhs->map[y][x] == 'C')
		hhs->c_count++;
	if (hhs->map[y][x] == 'P')
		hhs->p_count++;
	if (hhs->map[y][x] != '1' &&
			hhs->map[y][x] != '0' &&
			hhs->map[y][x] != 'P' &&
			hhs->map[y][x] != 'E' &&
			hhs->map[y][x] != 'C')
	{
		close_program("There seems to be an invalid character in map file.\n");
	}
}

/*
	This function serves two purposes - it iterates through the 
	map, each time calling item_count, and tests the number of 
	collectables, player and exit is correct.
*/

void	valid_count(t_game *hhs)
{
	int	y;
	int	x;

	y = 0;
	while (y < hhs->h - 1)
	{
		x = 0;
		while (x < hhs->w - 1)
		{
			item_count(hhs, y, x);
			x++;
		}
		y++;
	}
	if (hhs->c_count == 0)
		close_program("This map is snailless :'(\n");
	if (hhs->p_count < 1)
		close_program("This map has no slime! You need a slime!\n");
	if (hhs->p_count > 1)
		close_program("Too many slimes. Only one allowed per map. :'(\n");
	if (hhs->e_count < 1)
		close_program("No burrow. No bueno. A slime's burrow is his castle.\n");
	if (hhs->e_count > 1)
		close_program("This map has too many burrows.\n");
}
