#include "main.h"

void print_buffer(char buffer[], int *buffer_index);
/**
 * _printf - function
 * @format: parameter
 * Return:  the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	int a, ptd = 0, ptd_chars = 0;
	int flags, width, precision, size,
	    buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	
	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_index++] = format[a];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			ptd_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			ptd = handle_print(format, &a, list, buffer, flags, width, precision, size);

			if (ptd == -1)
				return (-1);
			ptd_chars += ptd;
		}
	}
	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (ptd_chars);
}
/**
 * print_buffer - will print what is in the buffer
 * @buffer: will serve as temporary storage
 * @buffer_index: will be used to add the next char
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	/*will write data from the specified buffer*/
	*buffer_index = 0;
}
