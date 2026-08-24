/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:35:16 by haincel           #+#    #+#             */
/*   Updated: 2026/08/24 11:35:16 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ar;
	size_t			slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (malloc(0));
	if (len > slen - start)
		len = slen - start;
	ar = (char *)malloc(len + 1);
	if (!ar)
		return (NULL);
	i = 0;
	while (s[start] && (i < len))
	{
		ar[i] = s[start];
		i++;
		start++;
	}
	ar[i] = '\0';
	return (ar);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ar;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ar = (char *)malloc((s1len + s2len + 1));
	if (!ar)
		return (NULL);
	ft_memcpy(&ar[0], s1, s1len);
	ft_memcpy(&ar[s1len], s2, s2len);
	ar [s1len + s2len] = '\0';
	return (ar);
}