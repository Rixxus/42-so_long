/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:38 by rmount            #+#    #+#             */
/*   Updated: 2023/05/05 11:59:28 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*
	This function checks the space the player wants to:
	- is not a wall
	- if it is a collectable, writes a message to the console
	and decrements the collectable count, if the collectable
	count reaches zero, prints an additional message.
	- if it is the exit and the collectable count is 0, it sets
	the end variable to 1 (true), prints a message and exits
	the program
	- if it is the exit but not all collectables are found,
	prints a message then returns -1 to take_step
	- if the keycode was not a valid direction, returns -1 to
	take_step
*/
static int	valid_move(t_game *hhs, int y, int x, int keycode)
{
	if (hhs->map[y][x] == '1')
		return (-1);
	if (hhs->map[y][x] == 'C')
	{
		ft_printf("NOM!\n");
		hhs->c_count--;
		if (hhs->c_count == 0)
			ft_printf("That was the last one.\nTime to head home for a nap.\n");
	}
	if (hhs->map[y][x] == 'E' && hhs->c_count == 0)
	{
		hhs->end = 1;
		ft_printf("Congratulations, you got all of");
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

/*
	This function is called by keypress_hook and calls 
	valid_move to test whether the step is permittable.
	If it is a permitted move, it updates the coordinates the 
	player has moved to to be a 0 (ground), resets the 
	playery and playerx to the new coordinates and updates
	the map to have a P on the coordinates.
	Finally, it prints the current move count.
*/

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

/*
	This function is called every time a key is pressed.
	It modifies the coordinates based on the direction 
	key pressed, and tests if end is set to 1 (true).
	If it is 0, it calls take_step passing through
	the updated coordinates and the keycode.
	We also test here if the keycode is the escape key,
	in which case we call exit_program. 
	Once take_step and returns, we call draw_map to
	update the appearance of the new positions 
	on screen.
*/

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
	draw_map(hhs);
	return (0);
}
