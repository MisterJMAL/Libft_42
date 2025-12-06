/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:32 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/18 09:16:14 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int	i;

	if (str == NULL || (*f) == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		(*f)(i, &str[i]);
		i++;
	}
}
