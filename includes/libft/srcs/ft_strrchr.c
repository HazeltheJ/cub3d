/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:51:23 by ajami             #+#    #+#             */
/*   Updated: 2024/10/26 14:39:27 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
