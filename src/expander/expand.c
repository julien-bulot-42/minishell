/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:12:30 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 17:45:01 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expand_tokens(t_token *tokens, char **envp, int last_status)
{
	while (tokens)
	{
		if (tokens->type == TOKEN_WORD && tokens->value)
		{
			tokens->value = expand_variable(tokens->value,
					envp, last_status);
		}
		tokens = tokens->next;
	}
}
