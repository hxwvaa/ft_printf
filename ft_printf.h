/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:46:24 by hbasheer          #+#    #+#             */
/*   Updated: 2024/07/01 17:52:00 by hbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	ft_printf(const char *format, ...);
ssize_t	ft_putchar(char c);
ssize_t	ft_puthexa(unsigned long long n, char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putptr(void *ptr);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putunbr(unsigned int n);

#endif