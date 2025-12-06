/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:45:10 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/18 08:54:22 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c);
static char	*str_dup(char const *str, int start, int end, char const *set);

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trimmed;
	int		i;
	int		j;

	if (str == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)str) - 1;
	while (is_set(set, str[i]) == 1 && i < j)
		i++;
	while (is_set(set, str[j]) == 1 && i < j)
		j--;
	trimmed = str_dup(str, i, j, set);
	return (trimmed);
}

static int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0' && set[i] != c)
		i++;
	if (set[i] == c)
		return (1);
	else
		return (0);
}

static char	*str_dup(char const *str, int start, int end, char const *set)
{
	char	*new_str;

	if (start == end && is_set(set, str[start]) == 0)
	{
		new_str = (char *)malloc(2 * sizeof(char));
		new_str[0] = str[start];
		new_str[1] = '\0';
		return (new_str);
	}
	else if (start == end)
	{
		new_str = (char *)malloc(1 * sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = ft_substr(str, start, end - start + 1);
	return (new_str);
}
