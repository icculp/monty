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
		printf("11\n");
		m.buff[strlen(m.buff) - 1] = '\0';
		printf("||BUFF: %s\n", m.buff);
		tok = strtok(m.buff, " ");
		printf("1.5\n");
		printf("TOKKK: %s\n", tok);
/**		printf("tok0: %c\n", tok[0]);*/
		if (tok == NULL || tok[0] == '#' || tok[0] == '\0')
		{
			printf("Ln: %d\n", m.linenumber++);
			continue;
		}
		while (tok != NULL)
		{
			m.margs[mi] = tok;
			printf("margsmi: %s, mi: %d\n", m.margs[mi], mi);
			tok = strtok(NULL, " ");
			mi++;
			if (mi > 2)
				break;
		}
		printf("22\n");
		ops();
		m.linenumber++;
	}
}
