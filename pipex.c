/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:49 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/21 14:05:43 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char **envp)
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