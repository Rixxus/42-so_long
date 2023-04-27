/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:38 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 12:03:51 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *hhs, int y, int x, int keycode)
{
	if (hhs->map[y][x] == '1')
		return (-1);
	if (hhs->map[y][x] == 'C')
	{
		ft_printf("Yummy, snails!\n");
		hhs->c_count--;
	}
	if (hhs->map[y][x] == 'E' && hhs->c_count == 0)
	{
		hhs->end = 1;
		ft_printf("Congratulations, you have absorbed all of");
		ft_printf(" the snails and sated the slime!\n");
		exit_program();
	}
	else if (hhs->map[y][x] == 'E')
	{
		ft_printf("You have not absorbed all of the snails! Feed the slime!\n");
		return (-1);
	}
	if (keycode != LEFT && keycode != RIGHT && keycode != UP && keycode != DOWN)
		return (-1);
	else
		return (0);
}

static void	take_step(t_game *hhs, int y, int x, int keycode)
{
	int	check;
	int	col;
	int	row;

	col = hhs->playery;
	row = hhs->playerx;
	check = valid_move(hhs, y, x, keycode);
	if (check != -1)
	{
		hhs->map[col][row] = '0';
		hhs->playery = y;
		hhs->playerx = x;
		hhs->map[y][x] = 'P';
		ft_printf("Move count: %i\n", hhs->moves++);
	}
}

int	keypress_hook(int keycode, t_game *hhs)
{
	int	y;
	int	x;

	y = hhs->playery;
	x = hhs->playerx;
	if (keycode == LEFT)
		x--;
	else if (keycode == RIGHT)
		x++;
	else if (keycode == UP)
		y--;
	else if (keycode == DOWN)
		y++;
	else if (keycode == ESC)
	{
		exit_program();
	}
	if (hhs->end != 1)
		take_step(hhs, y, x, keycode);
	parse_map(hhs);
	return (0);
}
