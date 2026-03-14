/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:32:52 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 15:37:31 by jbulot           ###   ########.fr       */
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

t_token	*extract_operator(char *str, int *i)
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
