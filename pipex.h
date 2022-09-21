/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:42:01 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/21 14:31:54 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H



#include <unistd.h>


typedef struct s_pipex
{
	char *cmd_path;
	char *cmd;
}	t_pipex;



int	ft_strncmp(const char *s1, const char *s2, size_t n);




#endif



