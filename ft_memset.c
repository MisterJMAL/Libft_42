/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:50:14 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/11 14:19:35 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			iteration;
	unsigned char	*pt;

	iteration = 0;
	pt = (unsigned char *) pointer;
	while (iteration < count)
	{
		pt[iteration] = value;
		iteration++;
	}
	return (pointer);
}
