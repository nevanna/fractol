/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:44:49 by htillman          #+#    #+#             */
/*   Updated: 2019/02/14 22:26:12 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_char(char c, char s)
{
	if (s == c)
	{
		return (1);
	}
	else
		return (0);
}

static size_t	ft_end(char const *s, char c)
{
	size_t	end;

	end = ft_strlen(s);
	end = end - 1;
	if (s[end] == c)
	{
		while (s[end] != c)
			end--;
	}
	return (end);
}

static void		ft_else(char const *s, size_t **iter, char c, char ***new)
{
	size_t	k;
	size_t	y;

	k = 0;
	k = ft_wlen(s, (*iter)[0], c);
	(*new)[(*iter)[1]] = (char *)malloc(sizeof(char) * (k + 1));
	if (!(*new)[(*iter)[1]])
	{
		while ((*iter)[1] > 0)
			free((*new)[(*iter)[1]--]);
		free((*new)[0]);
		free(*new);
		return ;
	}
	(*new)[(*iter)[1]][k] = '\0';
	y = 0;
	while (y < k)
	{
		(*new)[(*iter)[1]][y++] = s[((*iter)[0])++];
	}
	((*iter)[1])++;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	iter[2];
	size_t	*kostyl;
	size_t	i;

	i = 0;
	iter[0] = 0;
	iter[1] = 0;
	kostyl = iter;
	if (!s || !c)
		return (NULL);
	while (s[i] == c)
		i++;
	if (!s[i])
		return (new = ft_memalloc(sizeof(char*)));
	if (!(new = (char **)malloc(sizeof(char *) * (ft_nbofwords(s, c) + 1))))
		return (NULL);
	new[ft_nbofwords(s, c)] = NULL;
	while (kostyl[0] <= ft_end(s, c) && s[kostyl[0]] != '\0')
		(ft_check_char(s[kostyl[0]], c) == 1) ? ((kostyl[0])++)
		: ft_else(s, &kostyl, c, &new);
	return (new);
}
