#include "get_next_line.h"

int main()
{
	char *line;
	int fd = open("empty_file", O_RDONLY);
	int i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("%s (return: %d)\n", line, i);
		free(line);
	}
	close(fd);
}
