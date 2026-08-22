#include "get_next_line.h"
#include <unistd.h>

/* verılen byte kadar oku ıcınde \n var mı bak
varsa sag tarafı tut sol atrafı dondur */

char *check(char *str)
{

}


char *get_next_line(int fd)
{
	ssize_t i;
	char *line;
	static char *tut;

	tut = (char *)malloc(sizeof(char) * 10);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	
	i = read(fd, line, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return 0;
}