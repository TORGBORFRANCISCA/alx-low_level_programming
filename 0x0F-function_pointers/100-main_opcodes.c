#include <stdio.h>
#include <stdlib.h>
/**
 * main - generates opcodes.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i, number;
	char *arr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	number = atoi(argv[1]);

	if (number < 0)
	{
		printf("Error\n");
		exit(2);
	}
	arr = (char *)main;

	for (i = 0; i < number; i++)
	{
		printf("%02hhx", arr[i]);
		if (i  < number - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
