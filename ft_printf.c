#include "ft_printf.h"
#include <stdio.h>

int	check(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_puthexa(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += check(args, format[i]);
			i++;
		}
		else
		{
			len += putchar(format[i]);
			i++;
		}
		va_end(args);
	}
	return (len);
}
