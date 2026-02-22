/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:30:00 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/09 19:47:49 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
    t_node	*current;
    t_node	*compare;
    int		i;
    int		j;

    if (!stack || !stack->top)
        return ;
    i = 0;
    current = stack->top;
    while (i < stack->size)
    {
        current->index = 0;
        compare = stack->top;
        j = 0;
        while (j < stack->size)
        {
            if (current->value > compare->value)
                current->index++;
            compare = compare->next;
            j++;
        }
        current = current->next;
        i++;
    }
}
