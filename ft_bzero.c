/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:19:38 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/11 14:20:09 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	size_t			iteration;
	unsigned char	*pt;

	iteration = 0;
	pt = (unsigned char *) pointer;
	while (iteration < count)
	{
		pt[iteration] = 0;
		iteration++;
	}
}
