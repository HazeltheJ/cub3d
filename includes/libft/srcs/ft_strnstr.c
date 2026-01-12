/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:51:11 by ajami             #+#    #+#             */
/*   Updated: 2024/10/26 09:10:07 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			k = i + 1;
			j = 1;
			while (haystack[k] == needle[j] && k < len && needle[j] != '\0')
			{
				j++;
				k++;
			}
			if (needle[j] == '\0' && haystack[k - 1] == needle[j - 1])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
