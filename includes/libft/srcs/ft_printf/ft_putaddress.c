/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:46:01 by ajami             #+#    #+#             */
/*   Updated: 2024/12/25 13:46:01 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthexa(unsigned long long n)
{
	char	*tab;
	int		len;
	int		temp;

	len = 0;
	tab = "0123456789abcdef";
	if (n > 15)
	{
		temp = ft_puthexa(n / 16);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (ft_putchar(tab[n % 16]) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putaddress(void *ptr)
{
	int	len;
	int	temp;

	len = 0;
	if (!ptr)
	{
		temp = ft_putstr("0x0");
		if (temp == -1)
			return (-1);
		len = temp;
	}
	else
	{
		temp = ft_putstr("0x");
		if (temp == -1)
			return (-1);
		len += temp;
		temp = ft_puthexa((unsigned long)ptr);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}
