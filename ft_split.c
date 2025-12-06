/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:15:41 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/18 09:07:14 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static char	*fill_word(const char *str, int start, char c);
static int	word_len(const char *str, int start, char c);
static void	*ft_free(char **splitted, int count);

char	**ft_split(const char *str, char c)
{
	char	**splitted;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	splitted = ft_calloc((word_count(str, c) + 1), sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			splitted[j] = fill_word(str, i, c);
			if (splitted[j] == NULL)
				return (ft_free(splitted, j));
			j++;
			i = i + word_len(str, i, c);
		}
		else
			i++;
	}
	return (splitted);
}

static int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, char c)
{
	char	*word;
	int		i;

	word = (char *)malloc((word_len(str, start, c) + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[start + i] != c && str[start + i] != '\0')
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_len(const char *str, int start, char c)
{
	int	len;

	len = 0;
	while (str[start + len] != c && str[start + len] != '\0')
		len++;
	return (len);
}

static void	*ft_free(char **splitted, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}
