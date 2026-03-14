/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:59:29 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 17:29:21 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
# include "lexer.h"

void	expand_tokens(t_token *tokens, char **envp, int last_status);

char	*expand_variable(char *str, char **envp, int last_status);

#endif
