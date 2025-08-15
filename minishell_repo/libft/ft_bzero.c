/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:34:03 by chnaranj          #+#    #+#             */
/*   Updated: 2024/09/30 16:28:50 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int	main()
{
	char	s[20];
	size_t	n;
	n = 18;
	ft_bzero(s, n);
	return (0);
}

int main()
{
	char	s[] = "HOLA COMO TE VA LA MAÑANA DE HOY";
	size_t	n;
	n = 18;
	ft_bzero(s, n);
	printf(s, n);

	int	cont;
	cont = 0;

	while(cont < 20)
	{
		printf("%d",s[cont]);
		cont++;
	}
	return (0);
}*/
