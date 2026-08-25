#include "gnl.h"
#include "unistd.h"

char *has_new_line(char **hold)
{
	char *line;
	char *temp;
	int linelen;
	char *temph;

	if (!*hold)
		return (NULL);
	temp = ft_strchr(*hold, '\n');
	if (!temp)
		return (NULL);
	linelen = temp - *hold;
	line = ft_substr(*hold, 0, linelen + 1);
	temph = *hold;
	*hold = ft_substr(*hold, linelen + 1, (ft_strlen(*hold) - linelen - 1));
	free(temph);
	return (line);
}

char *get_next_line(int fd)
{
	char *red;
	static char *hold;
	char *line;
	char *temp;
	int i;

	red = (char *)malloc(BUFFER_SIZE + 1);
	if (!red)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, red, BUFFER_SIZE);
		if (i == -1)
		{
			free(red);
			return (0);
		}
		red[i] = '\0';
		temp = hold;
		hold = ft_strjoin(hold, red);
		free(temp);
		line = has_new_line(&hold);
		if (line)
			break;
		if (i == 0)
		{
			if (!*hold)
			{
				free(red);
				free(hold);
				hold = NULL;
				return (line);
			}
			line = hold;
			hold = NULL;
		}
	}
	free(red);
	return (line);
}
