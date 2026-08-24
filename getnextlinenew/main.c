#include <fcntl.h>
#include <stdio.h>
#include "gnl.h"

int main()
{
	int fd;
	fd = open("dosya.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}