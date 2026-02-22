/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:09:31 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/01 17:26:52 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node_to_end(t_stack **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = create_stack();
	if (!(*stack))
		return ;
	if (!(*stack)->top)
	{
		(*stack)->top = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->top->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = (*stack)->top;
		(*stack)->top->prev = new_node;
	}
	(*stack)->size++;
}

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack || !*stack)
		return ;
	if ((*stack)->top)
	{
		current = (*stack)->top;
		i = 0;
		while (i < (*stack)->size)
		{
			next = current->next;
			free(current);
			current = next;
			i++;
		}
	}
	free(*stack);
	*stack = NULL;
}
