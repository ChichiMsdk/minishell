/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:57:45 by chmoussa          #+#    #+#             */
/*   Updated: 2023/11/27 17:58:12 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_current_path(char *envp[])
{
	char	*path;

	return (path);
}

char	*get_path(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	*str_san(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		str++;
	return (str);
}

int	ft_exec(char *line, char **args, char **envp)
{
	char	*path;

	if (line[0] == '\0')
		return (1);
	if (strcmp(line, "exit") == 0)
		return (0);
	else if (strcmp(line, "echo") == 0)
		ft_echo(line, args, envp);
	else if (strcmp(line, "pwd") == 0)
		ft_pwd(line, args, envp);
	else
		printf("Command not found: %s\n", line);
	return (1);
}

int	ft_parse(char *line, char **envp)
{
	char	**args;
	int		i;
	int		j;

	j = 0;
	i = 0;
	args = ft_split(line, ' ');
	if (!args)
		return (0);
	if (!args[0])
	{
		free(args);
		return (1);
	}
	while (args[i])
		i++;
	j = ft_exec(args[0], args, envp);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (j);
}

int	main(int argc, char **argv, char *envp[])
{
	t_env	*env;
	char	*line;
	char	*prompt;
	char	*buffer;
	int		i;

	if (!envp[0])
		return (1);
	i = 0;
	while (1)
	{
		prompt = "minishell>";
		line = readline(prompt);
		buffer = str_san(line);
		if (!ft_parse(buffer, envp))
			break ;
		add_history(line);
		free(line);
	}
	free(line);
}
