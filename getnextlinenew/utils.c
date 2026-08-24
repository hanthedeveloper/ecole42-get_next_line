#include "gnl.h"

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