/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:30:00 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/11 18:14:48 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int number)
{
    int	i;

    if (number < 4)
        return (1);
    i = 2;
    while (i * i < number)
        i++;
    if (i * i > number)
        return (i - 1);
    return (i);
}

static int	find_max_index_position(t_stack *stack)
{
    t_node	*current;
    int		max_index;
    int		position;
    int		i;

    current = stack->top;
    max_index = current->index;
    position = 0;
    i = 0;
    while (i < stack->size)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            position = i;
        }
        current = current->next;
        i++;
    }
    return (position);
}

static void	k_sort_push_to_b(t_stack *a, t_stack *b)
{
    int	i;
    int	range;
    int	size;

    size = a->size;
    i = 0;
    range = ft_sqrt(size) * 14 / 10;
    while (a->size > 0)
    {
        if (a->top->index <= i)
        {
            pb(a, b, 1);
            rb(b, 1);
            i++;
        }
        else if (a->top->index <= i + range)
        {
            pb(a, b, 1);
            i++;
        }
        else
            ra(a, 1);
    }
}

static void	k_sort_push_to_a(t_stack *a, t_stack *b)
{
    int	rb_count;
    int	rrb_count;
    int	target_pos;

    while (b->size > 0)
    {
        target_pos = find_max_index_position(b);
        rb_count = target_pos;
        rrb_count = b->size - target_pos;
        if (rb_count <= rrb_count)
        {
            while (rb_count-- > 0)
                rb(b, 1);
        }
        else
        {
            while (rrb_count-- > 0)
                rrb(b, 1);
        }
        pa(a, b, 1);
    }
}

void	k_sort(t_stack *a, t_stack *b)
{
    index_stack(a);
    k_sort_push_to_b(a, b);
    k_sort_push_to_a(a, b);
}