/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:15:30 by rmount            #+#    #+#             */
/*   Updated: 2023/04/25 17:04:58 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate(t_game *hhs)
{
    static int counter;
    int x = 100;
    int y = 100;
    
    if (counter <= 99)
    {
        hhs->slime = mlx_xpm_file_to_image(hhs->mlx, "images/slime2.xpm", &x, &y);
    }
    if (counter > 99 && counter < 200)
    {
        hhs->slime = mlx_xpm_file_to_image(hhs->mlx, "images/slime4.xpm", &x, &y);
    }
    if (counter > 200)
    {
        counter = 0;
    }
    counter++;
    return (1);
}

int	main(int argc, char **argv)
{
	t_game	hhs;

	if (argc != 2)//if the argument count is less than 2 then we cannot go on
	{
		return (0);
	}
	ft_memset(&hhs, 0, sizeof(t_game));//populate the variables in the struct
	create_map(&hhs, argv[1]); //read the map document and get the specs
	map_check(&hhs);
	hhs.mlx = mlx_init();//initialise the minilibx library
	hhs.win = mlx_new_window(hhs.mlx, hhs.map_w * 100, hhs.map_h * 100,
			"Hungry, hungry slime");//open up a game window	
	convert_image(&hhs);//set up the visual elements
	put_image(&hhs);
	mlx_key_hook(hhs.win, deal_key, &hhs);//respond to player actions
	mlx_hook(hhs.win, 17, 0, (void *)exit, 0);//exit cleanly when x button used
    mlx_loop_hook(hhs.mlx, animate, &hhs);
	mlx_loop(&hhs.mlx);
}

int	exit_game(t_game *hhs)//freeing all the space used up by the game & map
{
	int	line;

	mlx_destroy_window(hhs->mlx, hhs->win);
	free(hhs->mlx);
	line = 0;
	while (line < hhs->map_h - 1)
	{
		free(hhs->map[line++]);
	}
	free(hhs->map);
	exit(0);
}
