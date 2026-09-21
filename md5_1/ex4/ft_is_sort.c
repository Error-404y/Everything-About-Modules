/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:41:07 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/20 08:41:09 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;
	int	cmp;

	i = 0;
	order = 0;
	while (i < length - 1)
	{
		cmp = f(tab[i], tab[i + 1]);
		if (cmp != 0)
		{
			if (order == 0)
			{
				if (cmp < 0)
					order = -1;
				else
					order = 1;
			}
			else if ((order < 0 && cmp > 0)
				|| (order > 0 && cmp < 0))
				return (0);
		}
		i++;
	}
	return (1);
}
