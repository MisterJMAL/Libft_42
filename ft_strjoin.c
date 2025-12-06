/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:34:17 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/03 15:12:41 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*join;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	join = (char *)malloc((ft_strlen((char *)str1) + ft_strlen((char *)str2)
				+ 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
		join[j++] = (char)str1[i++];
	i = 0;
	while (str2[i] != '\0')
		join[j++] = str2[i++];
	join[j] = '\0';
	return (join);
}
