/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:57:47 by chmoussa          #+#    #+#             */
/*   Updated: 2023/11/27 17:57:47 by chmoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <termios.h>
#include <ncurses.h>
#include <term.h>
#include <signal.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/signal.h>
#include <sys/param.h>
#include <sys/select.h>
#include <pwd.h>
#include <curses.h>
#include <termcap.h>
#include <time.h>
#include <grp.h>
#include <editline/readline.h>
#include <editline/history.h>
#include "include/libft/libft.h"

typedef struct s_env
{
	char *name;
	char *value;
	struct s_env *next;
} t_env;

int		ft_exec_path(char *line, char **args, char **envp);
char 	**get_bin(char ***args, char **envp);
int		ft_env(char *line, char **args, char **envp);
int		ft_dispatch(char *line, char **envp);
int		ft_parse(char *line, char ***args, char **envp);
int		ft_pwd(char *line, char **args, char **envp);
int		ft_echo(char *line, char **args, char **envp);
char	*get_current_path(char *envp[]);
int		ft_exec(char *line, char **args, char **envp);
int		ft_exit(char *line, char **args, char **envp);
int		relative_or_absolute(char *line);
int		ft_ls(char *line, char **args, char **envp);
int		ft_whereis(char *line, char **args, char **envp);
int	ft_path(char *line,char **args, char **envp);
int	ft_clear(char *line, char **args, char **envp);
#endif
