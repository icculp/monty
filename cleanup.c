#include "monty.h"

/**
* cleanup - Free vars and close open file stream
*/

void cleanup(void)
{
	free(m.buff);
	free_dlistint(m.stack);
	free(m.margs);
	fclose(m.fd);
}
