/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:31:25 by mabada-r          #+#    #+#             */
/*   Updated: 2025/10/19 15:25:38 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*punt;

	punt = malloc(nmemb * size);
	if (punt)
	{
		ft_bzero(punt, (nmemb * size));
		return (punt);
	}
	return (NULL);
}
