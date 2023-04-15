/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:21:58 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 09:12:57 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Function takes a string as input along with a variable number of arguments.
 * To support a variable number of parameters, we use a va_list to store the 
 * argument list.
 * 
 * COUNT - we use a variable called count to store the total number of 
 * characters printed.
 * We += ft_char_type in the first if to add the number of character's printed 
 * each time the function is called to the count total.
 * We count++ in the second if after calling ft_putchar_fd to add one to the 
 * total of count.
 *
 * FIRST IF - is entered if the character is a format specifier - found by a % 
 * followed by anything that isn't null - and passes the char to ft_char_type 
 * which will pass it to the appropriate function to print it.
 *
 * SECOND IF - is entered if the character is not a format specifier, meaning 
 * it must be the string to print - which passes the char to ft_putchar_fd to 
 * print it.*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	v;

	va_start(v, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
		{
			count += ft_char_type(str[i], v, &i);
			i++;
		}
		if (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(v);
	return (count);
}
