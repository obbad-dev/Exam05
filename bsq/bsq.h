#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ELEMENT {
	size_t lines;
	char empty;
	char obstacle;
	char full;
} Element;

bool bsq(FILE *file);
