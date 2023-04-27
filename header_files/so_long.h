/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:07:12 by rmount            #+#    #+#             */
/*   Updated: 2023/04/27 11:42:43 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "ft_printf.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_game
{
	void	*slime;
	void	*ground;
	void	*burrow;
	void	*tree;
	void	*snail;
	int		p_count;
	int		c_count;
	int		e_count;
	int		playerx;
	int		playery;
	int		counter;
	int		moves;
	int		end;
	char	**map;
	char	**map_copy;
	int		cpy_c_count;
	int		cpy_e_count;
	int		w;
	int		h;
	int		fd;
	void	*mlx;
	void	*win;
	void	*img;
}	t_game;

void 	animate(t_game *hhs);
int		close_program(char *str);
int		exit_program(void);
void	place_slime(t_game *map, int height, int width);
void	place_snail(t_game *map);
int		check_map_file(char *str);
void	check_walls(t_game *map);
void	valid_count(t_game *map);
int		valid_map(t_game *map);
int		keypress_hook(int keycode, t_game *map);
void	render_map(t_game *map);
void	parse_map(t_game *map);
void	copy_map(char **origin_map, char **copy_map);
#endif