/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:58:09 by ajami             #+#    #+#             */
/*   Updated: 2024/12/29 15:58:09 by ajami            ###   ########.fr       */
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

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = ft_len(n);
	if (n > 9)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len);
}
