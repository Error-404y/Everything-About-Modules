/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <dloukats@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:13:32 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/17 09:22:51 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ex3/ft_recursive_power.c */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
