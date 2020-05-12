#include "monty.h"

int main(int ac, char **av)
{
	int fd;
	int line;
	char *buff;

	if (ac != 2)
	{
		dprintf(STDERR, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], r);
	if (fd = -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = getline(&buff, &len, fd)) != -1)
	{
		
	}
	free(buff);
	exit(EXIT_SUCCESS);
