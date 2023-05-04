/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:07 by rmount            #+#    #+#             */
/*   Updated: 2023/05/04 15:33:47 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function simply initialises all of the counter components of the 
	structure to the required values at start of game.
*/

static void	init_components(t_game *hhs)
{
	hhs->p_count = 0;
	hhs->c_count = 0;
	hhs->e_count = 0;
	hhs->cpy_c_count = 0;
	hhs->cpy_e_count = 0;
	hhs->end = 0;
	hhs->counter = 0;
	hhs->moves = 1;
}

/*
	This function is called by read_map and counts then returns the
	length of str (the first row of the map).
*/

static int	get_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

/*
	This function builds the game instance using the t_game struct (new). 
	It goes through a number of	steps:
	- callocs the variable (new) to be the corrrect size of the struct
	- opens the map file
	- assigns an fd to new which is returned by the open function
	- initialises the height(h) of new to 0
	- checks that the file descriptor is valid (greater than 0)
	- uses get_next_line to read the height of the map(h)
	- closes the map file
	- callocs new's map to be the correct size for the height (rows)
	- reopens the map file
	- uses get next line to copy each line into the map
	- closes the map file
	- gets the width of the map with get_width and assigns it to 
	new's width(w)
	- returns new to main()
*/

t_game	*read_map(char *argv)
{
	t_game	*new;
	int		y;

	new = (t_game *) ft_calloc(1, sizeof(t_game));
	new->fd = open(argv, O_RDONLY);
	new->h = 0;
	y = 0;
	if (new->fd < 0)
	{
		close_program("Map file does not exist\n");
	}
	while (get_next_line(new->fd))
		new->h += 1;
	close (new->fd);
	new->map = (char **) ft_calloc(new->h + 1, sizeof(char *));
	new->fd = open(argv, O_RDONLY);
	while (y < new->h)
	{
		new->map[y] = get_next_line(new->fd);
		y++;
	}
	close(new->fd);
	new->w = get_width(new->map[0]);
	return (new);
}

int	main(int argc, char **argv)
{
	t_game	*hhs;

	if (argc != 2)
	{
		close_program("Invalid number of arguments, there must be 2.\n");
	}
	if (check_map_file(argv[1]))
	{
		close_program("Map must be a .ber file\n");
	}
	hhs = read_map(argv[1]);
	init_components(hhs);
	valid_map(hhs);
	hhs->mlx = mlx_init();
	hhs->win = mlx_new_window(hhs->mlx, hhs->w * 50, hhs->h * 50,
			"Hungry, hungry slime");
	assign_images(hhs);
	draw_map(hhs);
	mlx_hook(hhs->win, 17, 0, exit_program, NULL);
	mlx_hook(hhs->win, 2, 1L << 0, keypress_hook, hhs);
	mlx_loop_hook(hhs->mlx, (void *)animate, hhs);
	mlx_loop(hhs->mlx);
}
