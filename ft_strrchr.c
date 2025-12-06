/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:11 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/17 10:55:13 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		iteration;
	char	*found;
	char	caract;

	iteration = 0;
	found = NULL;
	caract = (char) c;
	while (str[iteration] != '\0')
	{
		if (str[iteration] == caract)
			found = (char *)&str[iteration];
		iteration++;
	}
	if (str[iteration] == caract)
		found = (char *)&str[iteration];
	return (found);
}
