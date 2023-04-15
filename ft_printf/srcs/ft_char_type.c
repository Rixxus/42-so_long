/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:49:41 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 09:16:46 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function is called when printf finds a format specifier.
 * 
 * If c matches the condition for an if statement, it calls the 
 * corresponding function to deal with printing c, passing the
 * appropriate parameters for each, and returning the number of 
 * characters printed to ft_printf.*/

int	ft_char_type(const char c, va_list v, int *i)
{
	if (c == 'c')
		return (ft_char_print(va_arg(v, int)));
	if (c == 's')
		return (ft_str_print(v));
	if (c == 'i' || c == 'd')
		return (ft_num_print(va_arg(v, int)));
	if (c == 'u')
		return (ft_num_print(va_arg(v, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex_print(va_arg(v, unsigned int), c));
	if (c == 'p')
		return (ft_hex_print(va_arg(v, unsigned long), c));
	if (c == '%')
		return (ft_char_print(c));
	if (!c)
		return (0);
	else
		*i = *i - 1;
	return (0);
}
