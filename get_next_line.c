/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 02:19:30 by jleclerc          #+#    #+#             */
/*   Updated: 2025/12/11 16:30:30 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*join;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	join = (char *)malloc((ft_strlen((char *)str1) + ft_strlen((char *)str2)
				+ 2) * sizeof(char));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
		join[j++] = (char)str1[i++];
	i = 0;
	while (str2[i] != '\0' && str2[i] != SEP)
		join[j++] = str2[i++];
	join[j++] = str2[i];
	join[j] = '\0';
	free((char *)str1);
	return (join);
}

char	*fill_line(int fd, char *line, char *buffer)
{
	int		bytes_reads;
	char	*next_line;

	while (1)
	{
		if (ft_strchr(buffer, SEP) == NULL)
		{
			bytes_reads = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE
					- ft_strlen(buffer));
			if (bytes_reads <= 0 && buffer[0] == 0)
				break ;
		}
		line = ft_strjoin_sep(line, buffer);
		next_line = ft_strchr(buffer, SEP);
		if (next_line != NULL)
		{
			bytes_reads = ft_strlen(next_line + 1);
			buffer = ft_memcpy(buffer, next_line + 1, bytes_reads);
			ft_bzero(buffer + bytes_reads, BUFFER_SIZE - bytes_reads);
			break ;
		}
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	line = malloc(1);
	line[0] = '\0';
	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	line = fill_line(fd, line, buffer);
	if (line == NULL || ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
