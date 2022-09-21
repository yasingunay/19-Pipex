/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:49 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/21 14:58:03 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_paths(char **envp)
{
	int i;

	i = 0;
	while(ft_strncmp("PATH=",envp[i],5))
		i++;
	return *(envp + 5);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	char *options[3]={"ls", "-la", NULL};
	pipex.cmd = "ls";
	
	(void)argc;
	(void)argv;

	pipex.paths=find_paths(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');// free
	
	pipex.cmd_path = get_cmd_path();
	if (!pipex.cmd_path)
	{
		perror(pipex.cmd);
		return(-1);
	}
	
	execve(pipex.cmd_path,options,envp);
	printf("yasin");
	free(pipex.cmd_path);
	return (0);
}