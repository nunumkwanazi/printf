#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints a formatted string
 *
 * @format: String to be formatted
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
        int printed_chars = 0;
        va_list args;
        int i = 0;
        int (*f)(va_list, char *, unsigned int);

        if (format == NULL)
                return (-1);

        va_start(args, format);

        while (format[i])
        {
                if (format[i] == '%')
                {
                        i++;

                        f = get_format_function(&format[i]);

                        if (f != NULL)
                                printed_chars += f(args, NULL, 0);
                        else
                        {
                                if (format[i] != '\0')
                                {
                                        putchar('%');
                                        putchar(format[i]);
                                        printed_chars += 2;
                                }
                                else
                                        return (-1);
                        }

                        i++;
                }
                else
                {
                        putchar(format[i]);
                        printed_chars++;
                        i++;
                }
        }

        va_end(args);

        return (printed_chars);
}

