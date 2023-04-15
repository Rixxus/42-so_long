/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:22:11 by rmount            #+#    #+#             */
/*   Updated: 2023/03/12 10:27:30 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == 0)
	{
		return (NULL);
	}
	while (s[i])
	{
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}

/* This function takes a char pointer and counts the length of a string.
*/
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/* This function takes a char pointer and creates a null-terminating 
	copy which is returned. If the malloc fails, the function will return 
	NULL instead.
*/
char	*ft_strdup(const char *src)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	new = malloc(sizeof(*new) * (size + 1));
	if (!new)
	{
		return (NULL);
	}
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* This function takes two char pointers and creates a null-terminating
	concatenation of the two strings, which is returned. If the malloc
	fails, the function returns NULL.
*/
char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}