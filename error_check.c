/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:36:47 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/23 10:26:10 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_check(int input, char *error)
{
	if (input < 0)
	{
		write(2, error, ft_strlen(error));
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (input);
}
