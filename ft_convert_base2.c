/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 02:24:13 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/20 02:24:14 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	ft_find(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_skip_signs(char *nbr, int *sign)
{
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	*sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			*sign = -*sign;
		nbr++;
	}
	return (nbr);
}

int	ft_atoi_base(char *nbr, char *base)
{
	long	number;
	int		sign;
	int		base_len;
	int		digit;

	number = 0;
	base_len = ft_base_len(base);
	nbr = ft_skip_signs(nbr, &sign);
	digit = ft_find(*nbr, base);
	while (digit >= 0)
	{
		number = number * base_len + digit;
		nbr++;
		digit = ft_find(*nbr, base);
	}
	return ((int)(number * sign));
}