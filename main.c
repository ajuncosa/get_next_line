#include "get_next_line.h"

int main()
{
	char *line;
	int fd = open("long_line.txt", O_RDONLY);
	int fd2 = open("hola", O_RDONLY);
	int i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("%s (return: %d)\n", line, i);
		free(line);
	}

/*	i = get_next_line(fd, &line);
	printf("%s (return: %d)\n", line, i);
	i = get_next_line(fd2, &line);
	printf("%s (return: %d)\n", line, i);
	i = get_next_line(fd, &line);
	printf("%s (return: %d)\n", line, i);
	i = get_next_line(fd2, &line);
	printf("%s (return: %d)\n", line, i);*/
	close(fd);
	close(fd2);
}
