/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:22:59 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 17:42:13 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "expander.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	*tokens;

	(void)argc;
	(void)argv;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		add_history(line);
		tokens = lexer(line);
		expand_tokens(tokens, envp, 0);
		token_print(tokens);
		free(line);
	}
}
