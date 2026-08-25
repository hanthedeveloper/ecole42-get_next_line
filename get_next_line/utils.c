#include "gnl.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ar;
	size_t	i;

	i = 0;
	ar = (char *)malloc(ft_strlen(s) + 1);
	if (!ar)
		return (NULL);
	while (s[i])
	{
		ar[i] = s[i];
		i++;
	}
	ar[i] = '\0';
	return (ar);
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
		return (ft_strdup("");
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ar;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	ar = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ar)
		return (NULL);
	i = 0;
	while (s1 && i < ft_strlen(s1))
		ar[i] = s1[i++];
	i = 0;
	while (s2 && i < ft_strlen(s2))
		ar[ft_strlen(s1) + i] = s2[i++];
	ar[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ar);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ar;
	size_t	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	ar = (char *)malloc(s1len + ft_strlen(s2) + 1);
	if (!ar)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ar[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		ar[i] = s2[i - (ft_strlen(s1))];
		i++;
	}
	ar[i] = '\0';
	return (ar);
}
