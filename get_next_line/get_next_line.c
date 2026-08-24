#include "get_next_line.h"
#include <unistd.h>

/* verılen byte kadar oku ıcınde \n var mı bak
varsa sag tarafı tut sol atrafı dondur */

static char *give_line(char **str)
{
	unsigned int start;
	char *line;
	char *temp;

	temp = ft_strchr(*str, '\n');
	if (!temp)
		return (NULL);
	start = (temp - *str);
	line = ft_substr(str, 0, start + 1); // malloc 2
	*str = ft_substr(str, start + 1, ft_strlen(str) - 1 - start); // malloc 3
	if (!line)
		return (NULL);
	return (line);
}

char *get_next_line(int fd)
{
	ssize_t i;
	char *str;
	char *line;
	static char *hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1); // malloc 1
	if (!str)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		line = give_line(str);
		if (!line)
			return get_next_line(fd);
		hold = ft_strjoin(hold, str); // malloc 4
	}
	free(str);
	return (line);
}
