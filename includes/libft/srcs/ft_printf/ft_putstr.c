/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:43:15 by ajami             #+#    #+#             */
/*   Updated: 2024/12/22 16:43:15 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	len;
	int	temp;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		temp = ft_putchar(*str);
		if (temp == -1)
			return (-1);
		len += temp;
		str++;
	}
	return (len);
}
