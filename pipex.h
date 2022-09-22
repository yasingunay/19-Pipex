/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:42:01 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/22 12:05:05 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_pipex
{
	char *paths;
	char **cmd_paths;
	char *cmd;
	char *cmd_last;
	
}	t_pipex;



int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);




#endif



