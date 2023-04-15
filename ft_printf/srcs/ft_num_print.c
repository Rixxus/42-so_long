/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:11:58 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 10:30:18 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function (and its helper function) takes a number and prints it, then 
 * returns the count of written characters to ft_printf.
 *
 * First we check if the number is negative - if so we write a - using our
 * ft_putchar_fd, then set the number to negative - making it positive, and
 * increment count.
 *
 * Then we write the remaining characters with ft_put_num depending on whether 
 * they are single digit or more.
 *
 * If the number is more than one digit (>nine) we recursively call ft_put_num 
 * with a division by ten until the number becomes single digit, where it 
 * enters the second if loop and uses ft_putchar_fd to write the digit. 
 * This will end the most recent call to ft_put_num, and the second most recent
 * call it ft_put_num continues on to call ft_put_num with the modulus, which 
 * will leave us with the last digit of the number which is then taken to the
 * second if. This carries on until all the calls to ft_put_num are completed.
 *
 * If they are/when they become a single digit, we simply call ft_putchar_fd
 * to write the digit.
 *
 * After the number is written, we call num_length on the number with the radix
 * of ten, and return the count to ft_print. */

static void	ft_put_num(size_t n)
{
	if (n > 9)
	{
		ft_put_num(n / 10);
		ft_put_num(n % 10);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, 1);
	}
}

int	ft_num_print(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	ft_put_num(n);
	count += ft_num_length(n, 10);
	return (count);
}
