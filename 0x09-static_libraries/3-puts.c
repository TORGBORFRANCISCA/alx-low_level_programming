#include "main.h"
/**
 *  _puts - name of function
 *  @str: function parameter
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar ('\n');
}
