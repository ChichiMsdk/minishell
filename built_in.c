/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:48:13 by chmoussa          #+#    #+#             */
/*   Updated: 2023/11/27 17:48:13 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char *line, char **args, char **envp)
{
	pid_t	pid;
	char	*path;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("pwd failed to fork");
		free(line);
		exit(1);
	}
	if (pid == 0)
	{
		path = "/bin/pwd";
		execve(path, args, envp);
		printf("pwd failed to execve\n");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			printf("pwd exited with status %d\n", WEXITSTATUS(status));
		}
	}
	return (1);
}

int	ft_echo(char *line, char **args, char **envp)
{
	pid_t	pid;
	char	*path;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("echo failed to fork");
		free(line);
		exit(1);
	}
	if (pid == 0)
	{
		path = "/bin/echo";
		execve(path, args, envp);
		printf("echo failed to execve\n");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			printf("echo exited with status %d\n", WEXITSTATUS(status));
		}
	}
	return (1);
}
