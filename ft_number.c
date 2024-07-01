/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:46:26 by hbasheer          #+#    #+#             */
/*   Updated: 2024/07/01 12:46:27 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr(int n)
{
	ssize_t	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr("-2147483648");
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		len += ft_putnbr((n / 10));
		len += ft_putchar('0' + n % 10);
	}
	else
	{
		len += ft_putchar('0' + n);
	}
	return (len);
}

ssize_t	ft_puthexa(unsigned long long n, char c)
{
	ssize_t	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthexa(n / 16, c);
		len += ft_puthexa(n % 16, c);
	}
	else
	{
		if (n >= 10 && n <= 15)
		{
			if (c == 'X')
				len += ft_putchar(n - 10 + 'A');
			else if (c == 'x')
				len += ft_putchar(n - 10 + 'a');
		}
		else if (n <= 9)
		{
			len += ft_putchar(n + '0');
		}
	}
	return (len);
}

ssize_t	ft_putptr(void *ptr)
{
	ssize_t	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexa((unsigned long long)ptr, 'x');
	return (len);
}

ssize_t	ft_putunbr(unsigned int n)
{
	ssize_t	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunbr((n / 10));
		len += ft_putchar('0' + n % 10);
	}
	else
	{
		len += ft_putchar('0' + n);
	}
	return (len);
}
