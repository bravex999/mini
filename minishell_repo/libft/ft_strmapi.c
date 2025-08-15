/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:49:44 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/10 15:52:42 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
/*
int main(void)
{
    char original[] = "hola, mundo!";

    char to_uppermod(unsigned int i, char c)
    {
        (void)i;
        if (c >= 'a' && c <= 'z')
            return (c - 32);
        return (c);
    }

    char *modificada = ft_strmapi(original, to_uppermod);
    printf("Original: %s\n", original);
    printf("Modificada: %s\n", modificada);

    free(modificada); // Liberar la memoria asignada
    return 0;
}*/
