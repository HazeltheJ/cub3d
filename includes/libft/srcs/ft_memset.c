/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:38:11 by ajami             #+#    #+#             */
/*   Updated: 2024/10/26 16:50:55 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	cc;

	p = (unsigned char *)ptr;
	cc = (char)c;
	while (n-- > 0)
	{
		*p++ = cc;
	}
	return (ptr);
}
