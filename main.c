#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	for (size_t i = 0; i < 2; i++)
	{
		/* code */
		printf("%s", get_next_line(fd));
	}
}
