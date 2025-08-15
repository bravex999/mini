/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:29:57 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/08 14:30:11 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	char	*str;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (len > lens - start)
		len = lens - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
/*
int main ()
{
	char const *s = "Hola como estas";
	unsigned int start;
	size_t len;
	
	start = 1;
	len = 5;
	printf("%s", ft_substr(s, start, len));
	return (0);
}*/
