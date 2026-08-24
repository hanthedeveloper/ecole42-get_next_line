#include "get_next_line.h"
#include <unistd.h>

/* verılen byte kadar oku ıcınde \n var mı bak
varsa sag tarafı tut sol atrafı dondur */

static char *give_line(char *str)
{
	static char *tut;
	unsigned int start;
	char *line;
	char *temp;

	temp = ft_strchr(str, '\n');
	if (!temp)
		return (NULL);
	start = (temp - str);
	line = ft_substr(str, 0, start + 1);
	if (!line)
		return (NULL);
	tut = ft_substr(str, start + 1, (ft_strlen(str) - start - 1));
	if (!tut)
		return (NULL);
	return (line);
}

char *get_next_line(int fd)
{
	ssize_t i;
	char *str;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = read(fd, str, BUFFER_SIZE);
	if (i == -1)
	{
		free(str);
		return (NULL);
	}
	if (i == 0)
		return (str);
	
	line = give_line(str);
	free(str);
	return (line);
}