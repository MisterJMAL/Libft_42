/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:54:09 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/14 17:14:28 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (temp_src < temp_dest)
	{
		while (count-- > 0)
			temp_dest[count] = temp_src[count];
	}
	else
		ft_memcpy(dest, src, count);
	return (dest);
}
