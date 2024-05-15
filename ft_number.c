#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		len++;
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar('0' + n % 10);
		len++;
	}
	else
	{
		ft_putchar('0' + n);
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned long long n, char c)
{
	int	len;

	len = 0;
	if (n > 16)
	{
		len += ft_puthexa(n / 16, c);
		len += ft_puthexa(n % 16, c);
	}
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
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexa((unsigned long long)ptr, 'x');
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		ft_putunbr((n / 10));
		ft_putchar('0' + n % 10);
		len++;
	}
	else
	{
		ft_putchar('0' + n);
		len++;
	}
	return (len);
}
