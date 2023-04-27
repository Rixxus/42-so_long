/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:22:13 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 14:26:29 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	valid_shape(t_game *hhs)
{
	int	y;
	int	x;
	int	line;

	y = 0;
	x = 0;
	line = ft_strlen(hhs->map[0]);
	while (hhs->map[x] != 0)
	{
		y = ft_strlen(hhs->map[x]);
		if (y != line)
		{
			close_program("The map is not a rectangle\n");
		}
		x++;
	}
}

void	check_walls(t_game *hhs)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (hhs->map[y][x + 1])
	{
		if (hhs->map[y][x] != '1' || hhs->map[hhs->h - 1][x] != '1')
		{
			close_program("Map is not surrounded by walls\n");
		}
		x++;
	}
	while (hhs->map[y])
	{
		if (hhs->map[y][0] != '1' || hhs->map[y][hhs->w - 1] != '1')
		{
			close_program("Map is not surrounded by walls\n");
		}
		y++;
	}
	valid_shape(hhs);
}

/*
	Scans the map file and counts the number of each tile type.
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
		close_program("Invalid character in map file\n");
	}
}

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
		close_program("There are no snails\n");
	if (hhs->p_count < 1)
		close_program("There must be a slime in the game\n");
	if (hhs->p_count > 1)
		close_program("There can only be one slime in the game\n");
	if (hhs->e_count < 1)
		close_program("There must be a burrow in the game\n");
	if (hhs->e_count > 1)
		close_program("There can only be one burrow in the game\n");
}
