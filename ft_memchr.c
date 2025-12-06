/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:30:58 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/11 15:05:55 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	string = (unsigned char *)str;
	while (i < size)
	{
		if (string[i] == uc)
			return ((void *) &string[i]);
		i++;
	}
	return (NULL);
}
