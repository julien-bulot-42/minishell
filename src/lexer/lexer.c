/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:05:42 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/04 01:28:16 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static char	*extract_word(char *input, int *i)
{
	int		start;
	char	*word;
	int		len;
	int		j;

	start = *i;
	while (input[*i] && !is_space(input[*i])
		&& input[*i] != '|'
		&& input[*i] != '<'
		&& input[*i] != '>')
		(*i)++;
	len = *i - start;
	word = malloc(sizeof(*word) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = input[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	handle_operator(t_token **tokens, char *input, int *i)
{
	if (input[*i] == '|')
	{
		add_token(tokens, ft_strdup("|"), T_PIPE);
		(*i)++;
	}
	else if (input[*i] == '<' && input[*i + 1] == '<')
	{
		add_token(tokens, ft_strdup("<<"), T_HEREDOC);
		(*i) += 2;
	}
	else if (input[*i] == '>' && input[*i + 1] == '>')
	{
		add_token(tokens, ft_strdup(">>"), T_REDIR_APPEND);
		(*i) += 2;
	}
	else if (input[*i] == '<')
	{
		add_token(tokens, ft_strdup("<"), T_REDIR_IN);
		(*i)++;
	}
	else if (input[*i] == '>')
	{
		add_token(tokens, ft_strdup(">"), T_REDIR_OUT);
		(*i)++;
	}
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	char	*word;
	int		i;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else if (input[i] == '|' || input[i] == '<'
			|| input[i] == '>')
			handle_operator(&tokens, input, &i);
		else
		{
			word = extract_word(input, &i);
			if (!word)
				return (free_tokens(tokens), NULL);
			add_token(&tokens, word, T_WORD);
		}
	}
	return (tokens);
}
