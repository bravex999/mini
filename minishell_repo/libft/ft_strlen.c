/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:03:31 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/05 17:37:16 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/*	
int	main ()
{
	const char str[] = "Hola como estas";

	printf("%zu", ft_strlen(str));
	return (0);
}*/
