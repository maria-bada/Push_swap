/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:09:19 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/09 16:55:04 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_number_to_stack(t_stack **stack, char *str_num)
{
	long	num;
	t_node	*new_node;

	if (!is_valid_integer(str_num))
		return (0);
	num = ft_atol(str_num);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (is_duplicate(*stack, (int)num))
		return (0);
	new_node = create_node((int)num);
	if (!new_node)
		return (0);
	add_node_to_end(stack, new_node);
	return (1);
}

int	is_valid_integer(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
		len++;
	}
	if (len > 10)
		return (0);
	return (1);
}

int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (1)
	{
		if (current->value == num)
			return (1);
		current = current->next;
		if (current == stack->top)
			break ;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
