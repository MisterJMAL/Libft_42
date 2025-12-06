/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:19:33 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/18 09:20:17 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*extract;
	size_t	i;

	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	extract = ft_calloc(len + 1, sizeof(char));
	if (extract == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		extract[i] = str[start + i];
		i++;
	}
	return (extract);
}
