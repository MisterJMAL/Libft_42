/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:49:04 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/17 10:53:28 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		iteration;
	char	caract;

	iteration = 0;
	caract = (char) c;
	while (str[iteration] != '\0')
	{
		if (str[iteration] == caract)
			return ((char *)&str[iteration]);
		iteration++;
	}
	if (str[iteration] == caract)
		return ((char *)&str[iteration]);
	return (NULL);
}
