/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:47:25 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/17 11:23:05 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (str2[0] == 0)
		return ((char *) str1);
	while (str1[i] != '\0' && i < size)
	{
		while (str1[i + j] == str2[j] && str1[i + j] != '\0' && i + j < size)
		{
			j++;
			if (str2[j] == 0)
				return ((char *) str1 + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
