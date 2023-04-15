/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:07:55 by rmount            #+#    #+#             */
/*   Updated: 2022/02/03 11:26:42 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	i = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (s1_ptr[i] == s2_ptr[i] && i < n)
	{
		i++;
	}
	if (i < n)
		return (s1_ptr[i] - s2_ptr[i]);
	return (0);
}
