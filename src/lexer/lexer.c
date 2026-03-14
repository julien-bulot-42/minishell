/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:51:30 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 14:23:11 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static char	*extract_word(char *str, int *i)
{
	int		start;
	char	*word;
	int		len;

	start = *i;
	while (str[*i] && !is_space(str[*i]))
		(*i)++;
	len = *i - start;
	word = ft_strndup(str + start, len);
	return (word);
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	char	*word;
	int		i;

	i = 0;
	tokens = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else
		{
			word = extract_word(input, &i);
			token_add_back(&tokens, token_new(word, TOKEN_WORD));
		}
	}
	return (tokens);
}
