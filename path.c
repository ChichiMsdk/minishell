/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:52:54 by chmoussa          #+#    #+#             */
/*   Updated: 2023/11/27 22:52:54 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_path(char *line,char **args, char **envp)
{
	pid_t	pid;
	char	*path;
	int		status;

	path = line;
	pid = fork();
	if (pid == -1)
	{
		perror(" failed to fork");
		free(line);
		exit(1);
	}
	if (pid == 0)
	{
		execve(path, args, envp);
		printf("clear failed to execve\n");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			printf("clear exited with status %d\n", WEXITSTATUS(status));
		}
	}
	return (1);
}
