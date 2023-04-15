/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:28:13 by rmount            #+#    #+#             */
/*   Updated: 2022/02/18 13:41:58 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(char const *s, char delim)
{
	size_t	i;
	size_t	count;
	char	tru;

	i = 0;
	count = 0;
	tru = 1;
	while (s[i])
	{
		if (tru && s[i] != delim)
		{
			tru = 0;
			count++;
		}
		else if (!tru && s[i] == delim)
			tru = 1;
		i++;
	}
	return (count);
}

static char	*fillstring(char const**s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (str);
	ft_memcpy(str, *s, i);
	*s += i;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	count;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	count = num_words(s, c);
	strings = ft_calloc(count + 1, sizeof(char *));
	if (!strings)
		return (strings);
	while (i < count)
	{
		strings[i] = fillstring(&s, c);
		if (!strings[i])
			return (0);
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
