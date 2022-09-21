/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:47:12 by ygunay            #+#    #+#             */
/*   Updated: 2022/09/16 12:46:57 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1)+ft_strlen(s2);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[j + i] = '\0';
	return (dst);
}

// int main()
// {
// char s1[]="yasin";
// char s2[]="gunay";
// char *result;

// result=ft_strjoin(s1,s2);

// printf("%s\n",result );

// return(0);

// }

// int	main(void)
// {
// 	char	s1[] = "Hello";
// 	char	s2[] = " world!";
// 	char	*ret;

// 	ret = ft_strjoin(s1, s2);
// 	if (NULL == ret)
// 		printf("Ret is null!\n");
// 	else
// 		printf("Ret is '%s'\n", ret);
// 	free(ret);
// 	return (0);
// }