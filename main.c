/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:25:48 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/11 18:11:07 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
    t_node	*current;
    int		i;

    if (!stack || stack->size < 2)
        return (1);
    current = stack->top;
    i = 0;
    while (i < stack->size - 1)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
        i++;
    }
    return (1);
}

void	sort_two(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a, 1);
}

void	sort_three(t_stack *a)
{
    int	first;
    int	second;
    int	third;

    if (!a || a->size != 3 || is_sorted(a))
        return ;
    first = a->top->value;
    second = a->top->next->value;
    third = a->top->next->next->value;
    if (first > second && second < third && first < third)
        sa(a, 1);
    else if (first > second && second > third && first > third)
    {
        sa(a, 1);
        rra(a, 1);
    }
    else if (first > second && second < third && first > third)
        ra(a, 1);
    else if (first < second && second > third && first < third)
    {
        sa(a, 1);
        ra(a, 1);
    }
    else if (first < second && second > third && first > third)
        rra(a, 1);
}

void	sort_five(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return ;
    if (a->size == 5)
    {
        push_two_smallest_to_b(a, b);
        sort_three(a);
        push_back_sorted(a, b);
    }
    else if (a->size == 4)
    {
        push_smallest_to_b(a, b);
        sort_three(a);
        pa(a, b, 1);
    }
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
    int	pos;

    pos = find_smallest_position(a);
    while (pos != 0)
    {
        if (pos <= a->size / 2)
            ra(a, 1);
        else
            rra(a, 1);
        pos = find_smallest_position(a);
    }
    pb(a, b, 1);
}

void	push_two_smallest_to_b(t_stack *a, t_stack *b)
{
    int	pos;

    pos = find_smallest_position(a);
    if (pos <= 2)
        while (pos-- > 0)
            ra(a, 1);
    else
        while (pos++ < a->size)
            rra(a, 1);
    pb(a, b, 1);
    pos = find_smallest_position(a);
    if (pos <= 2)
        while (pos-- > 0)
            ra(a, 1);
    else
        while (pos++ < a->size)
            rra(a, 1);
    pb(a, b, 1);
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
    if (b->top->value < b->top->next->value)
        sb(b, 1);
    pa(a, b, 1);
    pa(a, b, 1);
}

int	find_smallest_position(t_stack *stack)
{
    t_node	*current;
    int		position;
    int		min;
    int		i;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    min = current->value;
    position = 0;
    i = 0;
    while (i < stack->size)
    {
        if (current->value < min)
        {
            min = current->value;
            position = i;
        }
        current = current->next;
        i++;
    }
    return (position);
}

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    if (argc < 2)
        return (0);
    stack_a = parse_arguments(argc, argv);
    stack_b = create_stack();
    if (!stack_a || !stack_b)
    {
        write(2, "Error\n", 6);
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    if (!is_sorted(stack_a))
    {
        if (stack_a->size == 2)
            sort_two(stack_a);
        else if (stack_a->size == 3)
            sort_three(stack_a);
        else if (stack_a->size <= 5)
            sort_five(stack_a, stack_b);
        else
            k_sort(stack_a, stack_b);
    }
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
