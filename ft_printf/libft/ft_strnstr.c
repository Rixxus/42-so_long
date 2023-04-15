/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:53:51 by rmount            #+#    #+#             */
/*   Updated: 2022/02/04 08:23:51 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}	
			j++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char haystack[] = "lorem ipsum dolor sit amet";
	char needle[] = "ipsumm";
	size_t len = 30;
	int	i = 0;
	char *result = ft_strnstr(haystack, needle, len);
	while (result[i])
	{
		printf("%c", result[i]);
		i++;	
	}
}*/
