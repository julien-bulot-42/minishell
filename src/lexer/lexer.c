/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:51:30 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 15:11:07 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

static t_token	*extract_operator(char *str, int *i)
{
	if (str[*i] == '|')
	{
		(*i)++;
		return (token_new(NULL, TOKEN_PIPE));
	}
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			(*i) += 2;
			return (token_new(NULL, TOKEN_APPEND));
		}
		(*i)++;
		return (token_new(NULL, TOKEN_REDIR_OUT));
	}
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			(*i) += 2;
			return (token_new(NULL, TOKEN_HEREDOC));
		}
		(*i)++;
		return (token_new(NULL, TOKEN_REDIR_IN));
	}
	return (NULL);
}

static char	*extract_word(char *str, int *i)
{
	int		start;
	char	*word;
	int		len;

	start = *i;
	while (str[*i] && !is_space(str[*i]) && !is_operator(str[*i]))
		(*i)++;
	len = *i - start;
	word = ft_strndup(str + start, len);
	return (word);
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	t_token	*new;
	char	*word;
	int		i;

	i = 0;
	tokens = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else if (is_operator(input[i]))
		{
			new = extract_operator(input, &i);
			token_add_back(&tokens, new);
		}
		else
		{
			word = extract_word(input, &i);
			token_add_back(&tokens, token_new(word, TOKEN_WORD));
		}
	}
	return (tokens);
}
