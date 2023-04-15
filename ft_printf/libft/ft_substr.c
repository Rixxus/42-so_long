/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:24:35 by rmount            #+#    #+#             */
/*   Updated: 2022/02/14 11:08:48 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			i;
	size_t			remain;

	if (start > ft_strlen(s))
		remain = 0;
	else
		remain = ft_strlen(s + start);
	if (remain < len)
		len = remain;
	result = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (result == NULL)
	{
		return (NULL);
	}
	while (i < len && s[i + start])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
