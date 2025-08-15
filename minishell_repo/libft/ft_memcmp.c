/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:06:31 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/08 17:14:52 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	src1 = (const unsigned char *) s1;
	src2 = (const unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	{
		while (i < n && (src1[i] == src2[i]))
			i++;
	}
	if (i == n)
		return (0);
	return (src1[i] - src2[i]);
}
