/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 02:24:28 by dloukats          #+#    #+#             */
/*   Updated: 2026/09/20 02:24:29 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_is_sep(str[i], charset))
			i++;
	}
	return (count);
}

static char	*ft_word_dup(char *str, char *charset, int *len)
{
	char	*word;
	int		i;

	*len = 0;
	while (str[*len] && !ft_is_sep(str[*len], charset))
		(*len)++;
	word = malloc(sizeof(char) * (*len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < *len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill_split(char **result, char *str, char *charset)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			result[j] = ft_word_dup(&str[i], charset, &len);
			if (!result[j])
				return (0);
			j++;
			i += len;
		}
	}
	result[j] = 0;
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!result)
		return (0);
	if (!ft_fill_split(result, str, charset))
		return (0);
	return (result);
}
