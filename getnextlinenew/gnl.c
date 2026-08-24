#include "gnl.h"
#include "unistd.h"

// read okudugu byte sayısını donduruyo bbufsize okumasını ıstedıgımız buyte sayısdı
//aaaa\nbbbbbbb\ncccc

char *has_new_line(char **hold)
{
	char *line;
	char *temp;

	temp = ft_strchr(*hold, '\n');
	line = ft_substr(*hold, 0, )
}

char *get_next_line(int fd)
{
	char *red;
	static char *hold;
	int i;

	red = (char *)malloc(BUFFER_SIZE + 1);
	i = 1;
	i = read(fd, red, BUFFER_SIZE);
	if (i == -1)
	{
		free(red);
		return (0);
	}
	red[i] = '\0';
	hold = 
	if (i == 0)
	{

	}
	return (0);
}