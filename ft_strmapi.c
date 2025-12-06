/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:16:29 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/14 18:10:13 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	if (str == NULL || (*f) == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)str))
	{
		result[i] = (*f)(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
