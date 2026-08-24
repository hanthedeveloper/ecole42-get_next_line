static char *give_line(char **str)
{
	unsigned int start;
	char *line;
	char *temp;

	temp = ft_strchr(str, '\n');
	if (!temp)
		return (NULL);
	start = (temp - str);
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

	hold = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1); // malloc 1
	if (!str)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		line = give_line(str);
		free(str);
	}
	return (line);
}
