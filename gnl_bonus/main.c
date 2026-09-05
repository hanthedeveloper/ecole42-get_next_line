#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open(0, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("[line %d, len=%zu] %s", n++, strlen(line), line);
		free(line);
	}
	printf("done\n");
	close(fd);
	return (0);
}