/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:44:38 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/09 16:59:48 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	my_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	counter(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	char	*start;

	start = (char *)s;
	while (*s && *s != c)
		s++;
	return (ft_substr(start, 0, s - start));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = ft_calloc(counter(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = get_word(s, c);
			if (!result[i++])
				return (my_free(result), NULL);
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	result[i] = NULL;
	return (result);
}

/*
int main() 
{
    const char *s = "Hola, mundo, este es un ejemplo";
    char c = ' ';
    char **result = ft_split(s, c);
    
    int i = 0;
    while (result[i] != NULL) {
        printf("%s\n", result[i]);
        i++;
    }
	return 0;
}*/
