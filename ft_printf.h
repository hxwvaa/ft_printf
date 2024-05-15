#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long long n, char c);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int n);
#endif