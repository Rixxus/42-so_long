/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:07:12 by rmount            #+#    #+#             */
/*   Updated: 2023/04/25 16:29:48 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
#include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "ft_printf.h"

typedef struct Game
{
	char	**map;
	int		map_h;
	int		map_w;

	void	*mlx;
	void	*win;

	void	*wall;
	void	*floor;
	void	*snail;
	void	*exit;
	void	*slime;

	int		locationw;
	int		locationh;
	int		snails;
	int		moves_count;

	int		p_count;
	int		c_count;
	int		e_count;
}	t_game;

int		create_map(t_game *hhs, char *path);
void	convert_image(t_game *hhs);
void	put_image(t_game *hhs);
int		deal_key(int key, t_game *hhs);
void	map_check(t_game *hhs);
int		exit_game(t_game *hhs);

#endif