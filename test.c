#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	static char *test[3];
	char *buffer[] = "Hello";
	int i = 0;

	while (buffer[i] != '\n' || buffer[i] != '\0')
	{
		test[i] = buffer[i];
		i++;
	}
	printf("%d", i);
}