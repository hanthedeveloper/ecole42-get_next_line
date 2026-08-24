/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:03:49 by haincel           #+#    #+#             */
/*   Updated: 2026/08/24 13:03:49 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char *give_line(char **hold)
{
	unsigned int start;
	char *line;
	char *temp;

	temp = ft_strchr(*hold, '\n');
	if (!temp)
		return (NULL);
	start = (temp - *hold);
	line = ft_substr(*hold, 0, start + 1);
	*hold = ft_substr(*hold, start + 1, ft_strlen(*hold) - 1 - start);
	if (!line)
		return (NULL);
	return (line);
}

static char *check_last_line(char **hold)
{
	char *temp;

	if (!hold)
		return (NULL);
	temp = ft_substr(*hold, 0, ft_strlen(*hold));
	if (!temp)
		return (NULL);
	return (temp);
}

static void ft_read(char **line, char **hold, int fd, char *str)
{
	ssize_t i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return 0;
		}
		str[i] = '\0';
		hold = ft_strjoin(hold, str);
		line = give_line(&hold);
		line = check_last_line(&hold);
		if (line)
			break;
	}
}

char *get_next_line(int fd)
{
	char *str;
	char *line;
	static char *hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	ft_read(&line, &hold, fd, str);
	free(str);
	return (line);
}