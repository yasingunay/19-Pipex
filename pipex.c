/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:49 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/22 12:23:04 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char **envp)
{
	int i;

	i = 0;
	while(ft_strncmp("PATH=",envp[i],5))
		i++;
	return (envp[i] + 5);
}

char *get_cmd(char **paths, char *cmd)
{
	char *tmp;
	char *command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if(access(command, F_OK | X_OK ) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}


int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	char *options[3]={"ls", "-la", NULL};
	pipex.cmd = "ls";
	
	(void)argc;
	(void)argv;

	pipex.paths=find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');// free
	
	pipex.cmd_last= get_cmd(pipex.cmd_paths, pipex.cmd);
	if (!pipex.cmd_last)
	{
		perror(pipex.cmd_last);
		return(-11);
	}
	
	execve(pipex.cmd_last,options,envp);
	printf("yasin");
	free(pipex.cmd_last);
	return (0);
}