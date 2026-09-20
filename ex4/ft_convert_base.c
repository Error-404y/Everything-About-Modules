/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 02:22:26 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/20 02:22:28 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_len(char *base);
int	ft_atoi_base(char *nbr, char *base);

static int	ft_result_len(int nbr, int base_len)
{
	long	n;
	int		len;

	n = nbr;
	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base(int nbr, char *base, int base_len)
{
	char	*result;
	long	n;
	int		len;

	len = ft_result_len(nbr, base_len);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	n = nbr;
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (len > (nbr < 0))
	{
		result[len - 1] = base[n % base_len];
		n /= base_len;
		len--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	value;
	int	base_to_len;

	if (ft_base_len(base_from) == 0)
		return (0);
	base_to_len = ft_base_len(base_to);
	if (base_to_len == 0)
		return (0);
	value = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(value, base_to, base_to_len));
}
