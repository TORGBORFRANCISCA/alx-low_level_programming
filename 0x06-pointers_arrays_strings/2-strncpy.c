#include "main.h"

/**
 * _strncpy - The main function of the code
 * @src: Function parameter
 * @dest: Function parameter
 * @n: Function parameter
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)

		dest[i] = src[i];
	while  (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
