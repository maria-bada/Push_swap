/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:05:31 by mabada-r          #+#    #+#             */
/*   Updated: 2025/10/21 16:55:31 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[i] && n > 1)
	{
		i++;
		n--;
	}
	while (src[j] && n > 1)
	{
		dst[i] = src[j];
		j++;
		i++;
		n--;
	}
	if (n != 0)
		dst[i] = '\0';
	return (ft_strlen(src) + dstlen);
}
