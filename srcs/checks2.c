/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:21:53 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 10:59:41 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' && str[i - 2] != 'e'
		&& str[i - 3] != 'b' && str[i - 4] != '.')
	{
		ft_printf("Error\nMap must be a .ber file\n");
		return (1);
	}
	return (0);
}

static void	flood_fill(t_game *copy, int paint, int y, int x)
{
	if (copy->map_copy[y][x] == '1')
		return ;
	else if (copy->map_copy[y][x] == 'C')
	{
		copy->cpy_c_count++;
		copy->map_copy[y][x] = '0';
	}
	else if (copy->map_copy[y][x] == 'E')
	{
		copy->cpy_e_count++;
		copy->map_copy[y][x] = '0';
	}
	if (copy->map_copy[y][x] == '0')
	{
		copy->map_copy[y][x] = paint;
		flood_fill(copy, paint, y, x + 1);
		flood_fill(copy, paint, y, x - 1);
		flood_fill(copy, paint, y + 1, x);
		flood_fill(copy, paint, y - 1, x);
	}
}

static int	valid_path(t_game *hhs, int y, int x)
{
	hhs->map_copy = malloc(sizeof(char *) * (hhs->w + 1));
	copy_map(hhs->map_copy, hhs->map);
	y = hhs->playery;
	x = hhs->playerx;
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
	return (1);
}

int	valid_map(t_game *hhs)
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
	return (0);
}
