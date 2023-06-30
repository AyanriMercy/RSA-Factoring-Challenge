#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: array of pointers to argument
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int number;
	int factor;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		return (1);
	}

	while (fscanf(file, "%d", &number) != EOF)
	{
		factor = 2;
		while (number % factor == 0)
		{
			number /= factor;
		}
		if (number == 1)
		{
			continue;
		}
		else
		{
			printf("%d=%d*%d\n", number, factor, number / factor);
		}
	}

	fclose(file);
	return (0);
}
