#include "main.h"


/**
 * main - main function.
 * @argc: argument counter.
 * @argv: argument Number.
 * Return: depend on condition.
 */

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char *bufline = NULL, *user_opcode = NULL;
	stack_t *stack = NULL;
	size_t bufline_length = 0;
	unsigned int line_number = 1;
	int i = 0;

	instruction_t instruction[] = {
		{"push", _push}, {NULL, NULL}
	};

	checker(argc, argv, file);
	while (getline(&bufline, &bufline_length, file) != -1 && !feof(file))
	{
		user_opcode = strtok(bufline, " \n");
		if (user_opcode == NULL)
		{
			line_number++;
			continue;
		}
		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp(user_opcode, instruction[i].opcode) == 0)
			{
				instruction[i].f(&stack, line_number);
				break;
			}
		}
		if (instruction[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unkown instruction %s\n", line_number, user_opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
