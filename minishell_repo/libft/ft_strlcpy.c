/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:35 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/09 17:06:48 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size -1 && s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(src));
}
/*
int main()
{
	char dst[11];
	const char *src = "Hola como estas Christian";
	size_t result;
	result = ft_strlcpy(dst, src, sizeof(dst));
	printf("%zu", result);
	printf("%s", dst);
	return (0);
}*/
