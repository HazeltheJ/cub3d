/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:45:52 by ajami             #+#    #+#             */
/*   Updated: 2024/12/29 14:45:52 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_len(n);
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (ft_len(n));
	}
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len);
}
