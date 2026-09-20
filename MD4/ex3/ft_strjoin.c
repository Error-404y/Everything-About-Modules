/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 02:22:05 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/20 02:22:06 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		len += ft_strlen(sep) * (size - 1);
	return (len);
}

static void	ft_copy(char *dest, int *pos, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		pos;

	result = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!result)
		return (0);
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_copy(result, &pos, strs[i]);
		if (i < size - 1)
			ft_copy(result, &pos, sep);
		i++;
	}
	result[pos] = '\0';
	return (result);
}
