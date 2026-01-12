/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 07:46:50 by ajami             #+#    #+#             */
/*   Updated: 2024/10/29 19:09:05 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char const *s1, char const *s2)
{
	if (!s1 && s2)
		return ((char *)s2);
	else if (!s2 && s1)
		return ((char *)s1);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;

	if (!s1 || !s2)
		return (check(s1, s2));
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s1)
	{
		tab[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		tab[i++] = *s2;
		s2++;
	}
	tab[i] = '\0';
	return (tab);
}
