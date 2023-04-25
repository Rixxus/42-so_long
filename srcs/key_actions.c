/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:14:59 by rmount            #+#    #+#             */
/*   Updated: 2023/04/25 17:07:23 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//start at deal_key function

static int	tile_check(t_game *hhs, int w, int h)
{
	if (hhs->map[h][w] == '0')//if player lands on a ground tile
	{
		hhs->map[h][w] = 'P';//that place becomes a player tile
		hhs->locationw = w;
		hhs->locationh = h;
		hhs->moves_count++;//increase the count for the number of moves
	}
	if (hhs->map[h][w] == 'C')//if player lands on a collectable
	{
		hhs->map[h][w] = 'P';//that place becomes a player tile
		hhs->locationw = w;
		hhs->locationh = h;
		hhs->snails--;//decrease the number of strawberries as one has been picked
		hhs->moves_count++;
	}
	if (hhs->map[h][w] == 'E')//if player lands on the exit
	{
		if (hhs->snails != 0)//if there are still collectables in the game then they cannot exit
			return (0);
		else//otherwise winner, winner chicken dinner
			ft_printf("Congratulations, the slime is sated!\n");
		exit_game(hhs);
	}
	return (1);
}

static int	up_or_down(t_game *hhs, int key)
{
	int	w;
	int	h;

	w = hhs->locationw;//tracking player's location
	h = hhs->locationh;
	if (key == 13)//player pressed "W" key to move up
	{
		h--; //move up the map
		if (hhs->map[h][w] == '1')//this is a bush and player cannot move into bushes
			return (0);
		if (!(tile_check(hhs, w, h)))//function to check the tile the player is stepping onto and trigger the result accordingly
			return (0);
		hhs->map[h + 1][w] = '0';//place ground image on the tile the player just left
	}
	else if (key == 1)//player pressed "S" key to move down
	{
		h++;//move down the map
		if (hhs->map[h][w] == '1')
			return (0);
		if (!(tile_check(hhs, w, h)))
			return (0);
		hhs->map[h - 1][w] = '0';
	}
	ft_printf("moves: %i\n", hhs->moves_count);
	return (1);
}

static int	l_or_r(t_game *hhs, int key)
{
	int	w;
	int	h;

	w = hhs->locationw;
	h = hhs->locationh;
	if (key == 0)//player pressed "A" key to move left
	{
		w--;//move left on the map
		if (hhs->map[h][w] == '1')
			return (0);
		if (!(tile_check(hhs, w, h)))
			return (0);
		hhs->map[h][w + 1] = '0';
	}
	else if (key == 2)//player pressed "D" key to move right
	{
		w++;//move right on the map
		if (hhs->map[h][w] == '1')
			return (0);
		if (!(tile_check(hhs, w, h)))
			return (0);
		hhs->map[h][w - 1] = '0';
	}
	ft_printf("moves: %i\n", hhs->moves_count);
	return (1);
}

int	deal_key(int key, t_game *hhs)//check what key the player has hit
{
	int	action;

	if (key == 13 || key == 1)
	{
		action = up_or_down(hhs, key);//function to determine if player is moving up or down
	}
	if (key == 0 || key == 2)
	{
		action = l_or_r(hhs, key);//function to determine if player is moving left or right
	}
	if (key == 53)//if they hit ESC
	{
		exit_game(hhs);
	}
	if (action)
	{
		put_image(hhs);
	}
	return (1);
}