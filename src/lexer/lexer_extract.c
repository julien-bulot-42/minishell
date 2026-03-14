/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:32:52 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 16:14:12 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*extract_word(char *str, int *i)
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

static t_token	*extract_pipe(int *i)
{
	(*i)++;
	return (token_new(NULL, TOKEN_PIPE));
}

static t_token	*extract_redir_out(char *str, int *i)
{
	if (str[*i + 1] == '>')
	{
		(*i) += 2;
		return (token_new(NULL, TOKEN_APPEND));
	}
	(*i)++;
	return (token_new(NULL, TOKEN_REDIR_OUT));
}

static t_token	*extract_redir_in(char *str, int *i)
{
	if (str[*i + 1] == '<')
	{
		(*i) += 2;
		return (token_new(NULL, TOKEN_HEREDOC));
	}
	(*i)++;
	return (token_new(NULL, TOKEN_REDIR_IN));
}

t_token	*extract_operator(char *str, int *i)
{
	if (str[*i] == '|')
		return (extract_pipe(i));
	if (str[*i] == '>')
		return (extract_redir_out(str, i));
	if (str[*i] == '<')
		return (extract_redir_in(str, i));
	return (NULL);
}
