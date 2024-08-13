#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, destination, r, w;
	char *buffer;

	if (argc != 3) /* argument count not valid */
	{
		/* print the correct program usage on the standard error */
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]); /* allocate memory for the buffer */
	from = open(argv[1], O_RDONLY);	 /* open the source file on read mode */
	r = read(from, buffer, 1024);	 /* read 1024 bytes from the file */
	/**
	 * open destination file for writing
	 * clears the content of the file when opening it
	 * with rw-rw-r-- or 0664 permision which grant read and write to the owner
	 *  and also the group but only read permission for others.
	 */
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1) /* check for errors */
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(destination, buffer, r); /* write to destination */

		if (destination == -1 || w == -1) /* check for write errors */
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024); /* read again from souce file */

	} while (r > 0); /* repeat if there is still content to copy */

	/* clear resources */
	free(buffer);
	/* close file descriptors */
	if (close(from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	if (close(destination) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destination);
		exit(100);
	}

	return (0);
}

/**
 * create_buffer - allocates a buffer - 1024 bytes
 * @file: name of file
 *
 * Return: pointer to the allocated memory
 */
char *create_buffer(char *file)
{
	char *buffer;

	/* allocate memry */
	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL) /* failed */
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}
