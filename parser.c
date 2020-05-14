#include "monty.h"

/**
* montyparser - Parses the monty bytecode file
*/

void montyparser(void)
{
	int mi = 0;
	char *tok;

	while ((m.line = getline(&m.buff, &m.len, m.fd)) != -1)
	{
		mi = 0;
		m.buff[strlen(m.buff) - 1] = '\0';
		tok = strtok(m.buff, " ");
		if (tok == NULL || tok[0] == '#' || tok[0] == '\0')
		{
		        m.linenumber++;
			continue;
		}
		while (tok != NULL)
		{
			m.margs[mi] = tok;
			tok = strtok(NULL, " ");
			mi++;
			if (mi > 2)
				break;
		}
		ops();
		m.linenumber++;
	}
}
