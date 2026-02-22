/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:17:18 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/01 17:17:19 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->next;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	b->top = b->top->next;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rra(t_stack *a, int print)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->prev;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print)
{
	if (!b || b->size < 2)
		return ;
	b->top = b->top->prev;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}