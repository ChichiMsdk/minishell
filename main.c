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
	return (str);
}

int	ft_exec(char *line, char **args, char **envp)
{
	char	*path;

	if (line[0] == '\0')
		return (1);
	if (strcmp(line, "exit") == 0)
		return (ft_exit(line, args, envp));
	else if (strcmp(line, "clear") == 0)
		return (ft_clear(line, args, envp));
	else if (strcmp(line, "echo") == 0)
		return (ft_echo(line, args, envp));
	else if (strcmp(line, "env") == 0)
		ft_env(line, args, envp);
	else if (strcmp(line, "/usr/bin/pwd") == 0)
		return (ft_pwd(line, args, envp));
	else if (strcmp(line, "whereis") == 0)
		return (ft_whereis(line, args, envp));
	else if (strcmp(line, "pwd") == 0)
		return (ft_pwd(line, args, envp));
	else
		printf("Command not found: %s\n", line);
	return (1);
}

void	freeFOU(char **args, char **clean)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	i = 0;
	if (!clean)
		return ;
	while (clean[i])
	{
		free(clean[i]);
		i++;
	}
	free(clean);
}

int	ft_dispatch(char *line, char **envp)
{
	char	**args;
	char	**clean;
	int		signal;
	int		j;

	clean = NULL;
	args = NULL;
	signal = ft_parse(line, &args, envp);
	if (signal)
	{
		freeFOU(args, clean);
		return (1);
	}
	if (relative_or_absolute(args[0]))
	{
		signal = ft_exec(args[0], args, envp);
		j = 0;
	}
	else
		signal = ft_exec(args[0], args, envp);
	freeFOU(args, clean);
	return (signal);
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
		if (!ft_dispatch(buffer, envp))
			break ;
		add_history(line);
		free(line);
	}
	free(line);
}
