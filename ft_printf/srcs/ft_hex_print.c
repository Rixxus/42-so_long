/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:51:51 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 13:36:37 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function takes a number and the char representing the type of format
 * specifier being passed and writes that number in hexadecimal format.
 *
 * First we count the number of digits with ft_num_count but we pass a radix
 * of sixteen to account for the result being a hexadecimal.
 *
 * Then we check if the char is p, indicating it is a pointer, in which case 
 * we write zero-x with ft_putstr_fd - indicating a hexadecimal number - 
 * increment the count by two for the characters printed, and reassign
 * the value of c to be x. 
 *
 * The second if is entered if n >= sixteen and recursively calls ft_hex_print
 * until n < sixteen, at which point it calls ft_putchar_fd to write the
 * relevant hexadecimal char. 
 * When the bottom recursive call closes, the second bottom call is re-entered
 * and the hexprint using %sixteen is called which must have a number less than
 * sixteen which is written using ft_putchar_fd. This continues until the 
 * entire number is written.
 *
 * We account for capitals or lower case by checking if the char is x, in 
 * which case we write n + eighty-seven - the difference between where n and
 * the lowercase letter representing it, or n + fifty-five if it is not lower 
 * case.
 * 
 * Lastly, count is returned to ft_printf. */

int	ft_hex_print(size_t n, char c)
{
	int	count;

	count = ft_num_length(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ft_hex_print(n / 16, c);
		ft_hex_print(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n + 87, 1);
		else
			ft_putchar_fd(n + 55, 1);
	}
	return (count);
}
