/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 12:11:59 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 15:37:14 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/* lexer */

t_token	*lexer(char *input);

/* token utils */

t_token	*token_new(char *value, t_token_type type);
void	token_add_back(t_token **list, t_token *new);
void	token_print(t_token *list);

/* lexer utils */

int		is_space(char c);
int		is_operator(char c);

/* token extraction */

char	*extract_word(char *str, int *i);
t_token	*extract_operator(char *str, int *i);

#endif
