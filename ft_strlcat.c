/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:12:28 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/20 12:12:39 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (len_dst > size)
		len_dst = size;
	if (size == len_dst)
		return (len_dst + len_src);
	if (size > (len_dst + len_src))
		ft_memcpy(dst + len_dst, src, len_src + 1);
	else
	{
		ft_memcpy(dst + len_dst, src, size - len_dst - 1);
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
