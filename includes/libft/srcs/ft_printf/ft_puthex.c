/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:24:55 by ajami             #+#    #+#             */
/*   Updated: 2024/12/29 16:24:55 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int n, char c)
{
	char	*tab;
	int		len;
	int		temp;

	len = 0;
	if (c == 'x')
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	if (n > 15)
	{
		temp = ft_puthex(n / 16, c);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (ft_putchar(tab[n % 16]) == -1)
		return (-1);
	len++;
	return (len);
}
