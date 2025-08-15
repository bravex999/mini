/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:55:53 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/08 19:37:55 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char    s[] = "Hola como estas";
    int c;
    c = 'o';
    size_t  n;
    n = 1;
    void *result;
    result = ft_memchr(s, c, n);
    if (result != NULL)
        printf("%s", (unsigned char *) result);
    else
        printf("%s", "NULL");
}*/
