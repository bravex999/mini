/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:55:21 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/09 17:06:17 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		dst_size;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (size + ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while (i + j < size -1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
	{
		dst[i + j] = '\0';
	}
	return (dst_size + ft_strlen(src));
}
/*
int	main ()
{
	char dst[30] = "holA";
	const char *src = "Hola como estas";
	printf("%zu",ft_strlcat(dst, src, sizeof(dst)));
	printf("%s", dst);
	return(0);
}*/
