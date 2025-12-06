/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:27:53 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/11 14:19:42 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t			iteration;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	iteration = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (iteration < count)
	{
		temp_dest[iteration] = temp_src[iteration];
		iteration++;
	}
	return (dest);
}
