/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:40 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/10 15:49:02 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	if (!f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main(void)
{
    char str[] = "hola, mundo!";

    void to_uppercase(unsigned int i, char *c)
    {
        (void)i;
        if (*c >= 'a' && *c <= 'z')
            *c -= 32;
    }

    ft_striteri(str, to_uppercase);
    printf("%s\n", str);
    return 0;
}*/
