/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 14:29:24 by haincel           #+#    #+#             */
/*   Updated: 2026/09/05 15:59:20 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static char	*has_new_line(char **hold)
{
	char	*line;
	char	*temp;
	int		linelen;
	char	*temph;

	if (!*hold)
		return (NULL);
	temp = ft_strchr(*hold, NL);
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

	line = has_new_line(hold);
	if (line)
		return (line);
	red = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!red)
		return (NULL);
	while (i != 0 && !ft_strchr(*hold, NL))
	{
		i = read(fd, red, BUFFER_SIZE);
		if (i == -1)
			return (free(red), free(*hold), *hold = NULL, NULL);
		red[i] = '\0';
		temp = *hold;
		*hold = ft_strjoin(*hold, red);
		free(temp);
	}
	free(red);
	return (has_new_line(hold));
}

static t_table	*ft_lstadd(t_table **lst, unsigned int fd, void *content)
{
	t_table	*nnode;

	if (!lst)
		return (NULL);
	nnode = (t_table *)malloc(sizeof(t_table));
	if (!nnode)
		return (NULL);
	nnode->fd = fd;
	nnode->content = content;
	nnode->next = *lst;
	*lst = nnode;
	return (nnode);
}

static t_table	*find_or_create_node(t_table **head, int fd)
{
	t_table	*temp;

	temp = *head;
	while (temp && temp->fd != (unsigned int)fd)
		temp = temp->next;
	if (!temp)
		temp = ft_lstadd(head, fd, NULL);
	return (temp);
}

char	*get_next_line_bonus(int fd)
{
	static t_table	*head;
	t_table			*temp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = find_or_create_node(&head, fd);
	if (!temp)
		return (NULL);
	line = ft_read(1, fd, (char **)&temp->content);
	if (line)
		return (line);
	if (!temp->content || !*(char *)temp->content)
	{
		free(temp->content);
		temp->content = NULL;
		return (NULL);
	}
	line = temp->content;
	temp->content = NULL;
	return (line);
}