/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:26:01 by haincel           #+#    #+#             */
/*   Updated: 2026/08/25 14:47:01 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "unistd.h"

static char	*has_new_line(char **hold)
{
	char	*line;
	char	*temp;
	int		linelen;
	char	*temph;

	if (!*hold)
		return (NULL);
	temp = ft_strchr(*hold, '\n');
	if (!temp)
		return (NULL);
	linelen = temp - *hold;
	line = ft_substr(*hold, 0, linelen + 1);
	temph = *hold;
	*hold = ft_substr((*hold), (linelen + 1), (ft_strlen(*hold) - linelen - 1));
	free(temph);
	return (line);
}

static char	*ft_read(int i, int fd, char **hold)
{
	char	*red;
	char	*temp;
	char	*line;

	red = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!red)
		return (NULL);
	line = NULL;
	while (i != 0 && !line)
	{
		i = read(fd, red, BUFFER_SIZE);
		if (i == -1)
		{
			free(red);
			return (0);
		}
		red[i] = '\0';
		temp = *hold;
		*hold = ft_strjoin(*hold, red);
		free(temp);
		line = has_new_line(hold);
	}
	free(red);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*line;
	int			i;

	i = 1;
	line = ft_read(i, fd, &hold);
	if (line)
		return (line);
	if (!hold || !*hold)
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	line = hold;
	hold = NULL;
	return (line);
}
