/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:37:59 by ajami             #+#    #+#             */
/*   Updated: 2025/04/23 00:12:43 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	check_format(char c)
{
	char	*tab;

	tab = "cspdiuxX%";
	while (*tab)
	{
		if (*tab == c)
			return (1);
		tab++;
	}
	return (0);
}

static int	handle_conversion(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == '%')
		count = ft_putchar('%');
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putaddress(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	int		temp;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && check_format(str[i + 1]))
			temp = handle_conversion(str[++i], args);
		else
		{
			temp = ft_putchar(str[i]);
			if (str[i] == '%')
				i++;
		}
		if (temp == -1)
			return (-1);
		len += temp;
		i++;
	}
	va_end(args);
	return (len);
}
