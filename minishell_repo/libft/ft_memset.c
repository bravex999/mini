/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:36:27 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/08 14:57:39 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	letter;
	size_t			i;
	char			*ptr;

	ptr = (char *) s;
	letter = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		ptr[i] = letter;
		i++;
	}
	return (s);
}
/*
int main ()
{
	char s[20];
	int c;
	size_t n;
	n = 15;
	c = 'R';
	printf("%s",(char*) ft_memset(s, c, n));
	return (0);
}*/
