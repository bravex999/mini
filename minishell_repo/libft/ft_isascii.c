/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:22:42 by chnaranj          #+#    #+#             */
/*   Updated: 2024/09/28 18:44:04 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

int	ft_isascii(int c)
{
	if (c >= '\0' && c <= '~' + 1)
		return (1);
	return (0);
}
/*
int	main ()
{
	int c;
	
	c = 124;

	int	result;

	result = ft_isascii(c);
	write(1, &(char){result + '0'}, 1);
	return (0);
}*/
