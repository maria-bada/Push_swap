/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:14:50 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/01 17:15:01 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	remove_from_src(t_stack *src)
{
	if (src->size == 1)
		src->top = NULL;
	else
	{
		src->top = src->top->next;
		src->top->prev = src->top->prev->prev;
		src->top->prev->next = src->top;
	}
	src->size--;
}

static void	add_to_empty_dest(t_stack *dest, t_node *node)
{
	dest->top = node;
	node->next = node;
	node->prev = node;
	dest->size = 1;
}

static void	add_to_nonempty_dest(t_stack *dest, t_node *node)
{
	node->next = dest->top;
	node->prev = dest->top->prev;
	dest->top->prev->next = node;
	dest->top->prev = node;
	dest->top = node;
	dest->size++;
}

static void	push_node(t_stack *dest, t_stack *src)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	remove_from_src(src);
	if (!dest->top)
		add_to_empty_dest(dest, node);
	else
		add_to_nonempty_dest(dest, node);
}

void	pa(t_stack *a, t_stack *b, int print)
{
	if (!b || !b->top)
		return ;
	push_node(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int print)
{
	if (!a || !a->top)
		return ;
	push_node(b, a);
	if (print)
		write(1, "pb\n", 3);
}
