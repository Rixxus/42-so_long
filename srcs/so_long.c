/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:07 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 15:42:43 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return (1);
	}
	if (check_map_file(argv[1]))
		return (1);
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
	return (0);
}
