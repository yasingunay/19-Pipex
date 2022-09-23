/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:42:01 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/23 10:18:51 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

typedef struct s_pipex
{
	pid_t pid1;
	pid_t pid2;
	int infile;
	int outfile;
	int end[2];
	char *paths;
	char **cmd_paths;
	char *cmd;
	char **cmd_args;
	
}	t_pipex;



int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int error_check (int input, char *error);
char *find_path(char **envp);
char *get_cmd(char **paths, char *cmd);
void first(t_pipex pipex, char ** argv , char **envp);
void second(t_pipex pipex, char ** argv , char **envp);
void	child_free(t_pipex *pipex);
void	parent_free(t_pipex *pipex);


#endif



