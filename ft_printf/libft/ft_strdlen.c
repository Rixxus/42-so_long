/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:32:44 by rmount            #+#    #+#             */
/*   Updated: 2022/02/15 08:34:02 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strdlen(const char *string, char delimeter)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != delimeter)
	{
		i++;
	}
	return (i);
}
