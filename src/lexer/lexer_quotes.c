/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:37:55 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 16:39:33 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lexer.h"

char	*extract_quoted_word(char *str, int *i)
{
	char	quote;
	int		start;
	int		len;
	char	*word;

	quote = str[*i];
	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	len = *i - start;
	word = ft_strndup(str + start, len);
	if (str[*i] == quote)
		(*i)++;
	return (word);
}
