#include "bsq.h"

bool isPrintibale(char c)
{
	return (c >= 32 && c <= 126);
}
bool fillElements(FILE *file, Element* elem)
{
	if (fscanf(file, "%ld%c%c%c\n", &elem->lines, &elem->empty, &elem->obstacle, &elem->full) !=4)
		return false;
	if (elem->lines <= 0 || elem->empty == elem->obstacle || elem->obstacle == elem->full)
		return false;
	if (!isPrintibale(elem->empty) || !isPrintibale(elem->full) || !isPrintibale(elem->obstacle))
		return false;

	// fprintf(stdout, "%ld %c %c %c\n", elem->lines, elem->empty,elem->obstacle, elem->full);
	return true;
}

size_t ft_strlen(char *line)
{
	size_t i = 0;
	while(line[i])
		i++;
	return i;
}

bool checkLine(char *line, Element *elem)
{
	size_t len = ft_strlen(line);
	for (size_t i = 0; i < len; i++)
	{
		if (line[i] != elem->empty && line[i] != elem->obstacle && line[i] != '\n')
			return false;
	}
	return true;
}


bool bsq(FILE *file)
{
	char *line = NULL;
	ssize_t bytRead;
	Element elem;
	size_t lent = 0;
	char **map;

	if (!fillElements(file, &elem))
		return false;
	map = calloc(elem.lines, sizeof(char *));
	size_t i = 0;
	size_t len = 0;
	while ((bytRead = getline(&line, &lent, file)) != -1)
	{
		if (i == elem.lines)
			return false;
		size_t lenght = ft_strlen(line);
		if (line[lenght-1] == '\n')
		{
			line[lenght - 1] = '\0';
			lenght--;
		}
		if (i == 0)
			len = lenght;
		else if (len != lenght)
			return false;
		map[i] = calloc(line, sizeof());
		if (!checkLine(line, &elem))
			return false;
		line = NULL;
		i++;
	}
	for (size_t i = 0; i < elem.lines; i++)
	{

		printf("%s \n", map[i]);
	}
	return true;
}