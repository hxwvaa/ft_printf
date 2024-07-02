/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:46:22 by hbasheer          #+#    #+#             */
/*   Updated: 2024/07/02 10:52:17 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	check(va_list args, const char c)
{
	ssize_t	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'p')
		len = ft_putptr(va_arg(args, void *));
	else if (c == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	ssize_t	len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
