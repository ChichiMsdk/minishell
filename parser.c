/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:02 by chmoussa          #+#    #+#             */
/*   Updated: 2023/11/27 17:50:02 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse(char *line, char ***args,  char **envp)
{
	int		i;

	i = 0;
	*args = ft_split(line, ' ');
	if (!*args)
		return (1);
	if (!*args[0])
	{
		free(*args);
		return (1);
	}
	return (0);
}

int	relative_or_absolute(char *line)
{
	if (line[0] == '/')
		return (1);
	else if (line[0] == '.' && line[1] == '/')
		return (1);
	else if (line[0] == '.' && line[1] == '.' && line[2] == '/')
		return (1);
	return (0);
}

char **get_bin(char ***args, char **envp)
{
	char	**clean;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	while ((*args)[i])
		i++;
	clean = malloc(sizeof(char *) * i);
	i = 1;
	while ((*args)[i])
	{
		clean[j] = ft_strdup((*args)[i]);
		i++;
		j++;
	}
	clean[j] = NULL;
	return (clean);
}
