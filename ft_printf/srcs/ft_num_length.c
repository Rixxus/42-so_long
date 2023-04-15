/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:49:38 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 13:27:30 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function counts the number of digits in a number by dividing by the
 * supplied radix - for decimal numbers it require ten, for hexadecimal
 * numbers it would require sixteen - and incrementing the counter each time 
 * a division is possible. */
int	ft_num_length(size_t n, int radix)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= radix;
		count++;
	}
	return (count);
}
