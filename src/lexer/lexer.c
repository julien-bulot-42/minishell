/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:51:30 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 15:32:30 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	handle_operator(char *input, int *i, t_token **tokens)
{
	t_token	*new;

	new = extract_operator(input, i);
	token_add_back(tokens, new);
}

static void	handle_word(char *input, int *i, t_token **tokens)
{
	char	*word;

	word = extract_word(input, i);
	token_add_back(tokens, token_new(word, TOKEN_WORD));
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	int		i;

	i = 0;
	tokens = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else if (is_operator(input[i]))
			handle_operator(input, &i, &tokens);
		else
			handle_word(input, &i, &tokens);
	}
	return (tokens);
}
