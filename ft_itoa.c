/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleclerc <jleclerc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:52:25 by jleclerc          #+#    #+#             */
/*   Updated: 2025/11/18 09:28:34 by jleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nbr;

	nbr = (long) n;
	len = len_int(nbr);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	len -= 1;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		result[len] = '0';
	while (nbr != 0)
	{
		result[len] = ((nbr % 10) + 48);
		nbr /= 10;
		len--;
	}
	return (result);
}

static int	len_int(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
