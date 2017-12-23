/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:50:07 by dsaadia           #+#    #+#             */
/*   Updated: 2017/11/14 21:03:24 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_move_pointer_to_end_of_next_word(char **str, char c)
{
	int		next_word_len;

	next_word_len = 0;
	while (**str == c && **str)
	{
		(*str)++;
	}
	while (**str != c && **str)
	{
		(*str)++;
		next_word_len++;
	}
	return (next_word_len);
}

char		**ft_strsplit(char const *str, char c)
{
	int		word_len;
	int		word_num;
	int		ct;
	char	**spl;

	word_num = 0;
	if (!str || !(spl = (char**)malloc(ft_strlen(str) * (sizeof(char*) + 2))))
		return (0);
	while (*str)
	{
		word_len = ft_move_pointer_to_end_of_next_word((char**)&str, c);
		if (word_len != 0 && *(str - word_len) != c)
		{
			if (!(spl[word_num] = (char*)malloc(word_len + 1)))
				return (0);
			ct = -1;
			while (++ct < word_len)
				spl[word_num][ct] = *(str - word_len + ct);
			spl[word_num][ct] = 0;
			word_num++;
		}
	}
	spl[word_num] = 0;
	return (spl);
}
