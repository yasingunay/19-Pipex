/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:12:34 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/23 10:25:42 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		i++;
	return (envp[i] + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first(t_pipex pipex, char **argv, char **envp)
{
	pipex.infile = open(argv[1], O_RDONLY);
	error_check(pipex.infile, "infile");
	error_check(dup2(pipex.infile, STDIN_FILENO), "dup2 infile");
	error_check(dup2(pipex.end[1], STDOUT_FILENO), "dup2 end[1]");
	close(pipex.end[0]);
	close(pipex.end[1]);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		write (2, "Command not found\n", 19);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second(t_pipex pipex, char **argv, char **envp)
{
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	error_check(pipex.outfile, "outfile");
	error_check(dup2(pipex.end[0], STDIN_FILENO), "dup2 end[0]");
	error_check(dup2(pipex.outfile, STDOUT_FILENO), "dup2 outfile");
	close(pipex.end[1]);
	close(pipex.end[0]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		write (2, "Command not found\n", 19);
		exit(127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
