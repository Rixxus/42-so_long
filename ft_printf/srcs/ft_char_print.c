/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:33:53 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 09:16:14 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function prints a single char - passed in as c - using our 
 * ft_putchar_fd function from libft, which uses the write function.
 *
 * It then returns one to be added to the total of characters printed to 
 * ft_printf. */
int	ft_char_print(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
