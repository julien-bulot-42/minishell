/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulot <jbulot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:19:47 by jbulot            #+#    #+#             */
/*   Updated: 2026/03/14 17:49:19 by jbulot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*get_env_value(char *name, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, len)
			&& envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return ("");
}

char	*expand_variable(char *str, char **envp, int last_status)
{
	if (str[0] != '$')
		return (str);
	if (str[1] == '?')
		return (ft_itoa(last_status));
	return (ft_strdup(get_env_value(str + 1, envp)));
}
