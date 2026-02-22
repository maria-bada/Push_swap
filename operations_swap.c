/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:04:08 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/01 17:27:34 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_node *first, t_node *second)
{
	t_node	*temp;

	if (!first || !second)
		return ;
	temp = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = temp;
	if (temp)
		temp->prev = second;
	temp = first->prev;
	first->prev = second->prev;
	if (second->prev)
		second->prev->next = first;
	second->prev = temp;
	if (temp)
		temp->next = second;
}

void	sa(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	swap_nodes(a->top, a->top->next);
	a->top = a->top->prev;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	swap_nodes(b->top, b->top->next);
	b->top = b->top->prev;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
