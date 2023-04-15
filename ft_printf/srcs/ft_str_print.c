/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 08:42:02 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 13:19:36 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Function takes the va_list passed from ft_char_type and prints with 
 * ft_putstr_fd (from libft)  either - (null) if str is null, or prints the 
 * string.
 *
 * It then calls ft_strlen and returns the count. */

int	ft_str_print(va_list v)
{
	char	*str;

	str = va_arg(v, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
