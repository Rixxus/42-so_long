/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:13:38 by rmount            #+#    #+#             */
/*   Updated: 2022/02/08 11:54:42 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;
	int		length;

	length = size * count;
	ptr = malloc(length);
	i = 0;
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, length);
	return (ptr);
}
