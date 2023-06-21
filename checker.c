#include "main.h"

/**
 * checker - checks if the args are correct.
 * @argc: argument counter.
 * @argv: argument vector:
 * @file: File.
*/

void checker(int argc, char *argv[], FILE *file)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}