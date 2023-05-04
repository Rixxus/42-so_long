/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:23:58 by rmount            #+#    #+#             */
/*   Updated: 2023/05/01 14:35:33 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function is called by the loop hook in so_long, passing the game
	instance and its data.
	Using a counter which is a static int (retains its value each time
	it's called), we change the image of the slime depending on what the
	value of the counter is.
	Once the counter exceeds the value of the last image, we reset it to 1.
	After (potentially) changing the image for the slime, we call draw_map
	to refresh the map image.
*/

void	animate(t_game *hhs)
{
	static int	counter = 1;
	int			x;
	int			y;

	if (counter <= 4)
		hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
				"images/slime150.xpm", &x, &y);
	if (counter > 4 && counter <= 8)
		hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
				"images/slime250.xpm", &x, &y);
	if (counter > 8 && counter <= 12)
		hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
				"images/slime350.xpm", &x, &y);
	if (counter > 12 && counter <= 16)
		hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
				"images/slime250.xpm", &x, &y);
	if (counter > 16 && counter <= 20)
		hhs->slime = mlx_xpm_file_to_image(hhs->mlx,
				"images/slime150.xpm", &x, &y);
	if (counter > 20)
		counter = 1;
	counter++;
	draw_map(hhs);
}

/*
	Just a handy little function to print a custom error message
	when exiting, passed in as a string.
*/

int	close_program(char *str)
{
	ft_printf("Error!\n%s", str);
	exit (1);
}

/*
	Just a handy little function to print a goodbye message when exiting.
*/
int	exit_program(void)
{
	ft_printf("Bye, thanks for playing!\n");
	exit (1);
}
