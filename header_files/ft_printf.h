/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:45:19 by rmount            #+#    #+#             */
/*   Updated: 2022/03/07 15:58:45 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int	ft_char_type(const char c, va_list v, int *i);
int	ft_printf(const char *str, ...);
int	ft_char_print(char c);
int	ft_str_print(va_list v);
int	ft_num_length(size_t n, int radix);
int	ft_hex_print(size_t n, char c);
int	ft_num_print(long long int n);

#endif
