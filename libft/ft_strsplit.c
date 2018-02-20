/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:19:55 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 10:01:04 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static	char	*ft_word(const char *str, char c, int *start)
{
	char	*s;
	int		k;

	s = (char *)malloc(sizeof(s) * (ft_strlen((char *)str)));
	if (!s)
		return (NULL);
	k = 0;
	while (str[*start] != c && str[*start])
	{
		s[k] = str[*start];
		k++;
		*start += 1;
	}
	s[k] = '\0';
	while (str[*start] == c && str[*start])
		*start += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		nbwords;
	char	**split;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	nbwords = ft_nb_words(str, c);
	split = (char **)malloc(sizeof(split) * (nbwords + 1));
	if (!split)
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < nbwords && str[i])
	{
		split[j] = ft_word(str, c, &i);
		j++;
	}
	split[j] = NULL;
	return (split);
}
