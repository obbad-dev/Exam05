#include "bsq.h"

int main (int ac, char *av[])
{
	FILE *file = NULL;

	if (ac == 1)
		file = stdin;
	else if(ac == 2)
	{
		file = fopen(av[1], "r");
		if (file == NULL)
			return 1;
	}
	else
		return 1;

	if (!bsq(file))
	{	
		if (file != stdin)
			fclose(file);

		fprintf(stderr, "Error: invalid map\n");
		return 1;
	}
	return 0;

}