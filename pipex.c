/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:49 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/22 16:17:44 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	int	status;
	int p;

	if(argc != 5)
	{
		write(2, "Invalid amount of arguments\n",29);
		exit(EXIT_FAILURE);
	}

	p =pipe(pipex.end);
	error_check(p,"pipe");
	
	
	pipex.paths=find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');// free

	pipex.pid1 = fork();
	if(pipex.pid1 == 0)
		first(pipex, argv, envp);
	pipex.pid2 = fork();
	if(pipex.pid2 == 0)
		second(pipex, argv ,envp);
	
	
	close(pipex.end[0]);
	close(pipex.end[1]);
	waitpid(pipex.pid1, &status, 0);
	waitpid(pipex.pid2, &status, 0);
	
	return (0);
}