/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:11:23 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/11 16:40:15 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar_fd_int(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_putstr_fd_int(char *str, int fd)
{
	int	len;

	if (str == NULL)
		return (ft_putstr_fd_int("(null)", 1));
	len = (int) ft_strlen(str);
	write(fd, str, len);
	return (len);
}

static int	ft_putnbr_fd_int(int n, int fd)
{
	long	nbr;
	char	digit;
	int		count;

	nbr = (long) n;
	count = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr > 9)
	{
		count += ft_putnbr_fd_int(nbr / 10, fd);
		count += ft_putnbr_fd_int(nbr % 10, fd);
	}
	else
	{
		digit = nbr + 48;
		write(fd, &digit, 1);
		count++;
	}
	return (count);
}

static int	ft_putunsigned(unsigned int nb)
{
	unsigned long	nbr;
	char			digit;
	int				count;

	nbr = (unsigned long) nb;
	count = 0;
	if (nbr > 9)
	{
		count += ft_putunsigned(nbr / 10);
		count += ft_putunsigned(nbr % 10);
	}
	else
	{
		digit = nbr + 48;
		write(1, &digit, 1);
		count++;
	}
	return (count);
}

static int	ft_puthexa(unsigned long c, int flag)
{
	char	*list;
	int		count;

	count = 0;
	if (flag == 0)
		list = "0123456789abcdef";
	else
		list = "0123456789ABCDEF";
	if (c > 15)
	{
		count += ft_puthexa(c / 16, flag);
		count += ft_puthexa(c % 16, flag);
	}
	else
		count += ft_putchar_fd_int(list[c], 1);
	return (count);
}

static int	ft_putptr(void *ptr)
{
	int		count;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr_fd_int("(nil)", 1));
	count += ft_putstr_fd_int("0x", 1);
	count += ft_puthexa((unsigned long)ptr, 0);
	return (count);
}

static int	checkformat(char c, va_list arg)
{
	if (c == '%')
		return (ft_putchar_fd_int('%', 1));
	if (c == 'c')
		return (ft_putchar_fd_int(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_fd_int(va_arg(arg, char *), 1));
	if (c == 'i')
		return (ft_putnbr_fd_int(va_arg(arg, int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	if (c == 'd')
		return (ft_putnbr_fd_int(va_arg(arg, int), 1));
	if (c == 'u')
		return (ft_putunsigned(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), 0));
	if (c == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += ft_putchar_fd_int(format[i], 1);
			i++;
		}
		else
		{
			count += checkformat(format[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}
