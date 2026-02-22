/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:09:06 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/09 17:34:20 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		result;

	if(argc < 2)
		return(NULL);
	stack_a = create_stack();
	if (!stack_a)
		return (NULL);
	i = 1;
	result = 1;
	while(i < argc && result == 1)
	{
		if(!process_combined_args(&stack_a, argv[i]))
			result = 0;
		i++;
	}
	if(result == 0)
	{
		free_stack(&stack_a);
		return(NULL);
	}
	return(stack_a);
}

int process_combined_args(t_stack **stack, char *arg)
{
	char	**numbers;
	int		i;
	int		result;

	if (ft_strchr(arg, ' '))
	{
		numbers = ft_split(arg, ' ');
		if(!numbers)
			return(0);
		i = 0;
		result = 1;
		while(numbers[i] && result == 1)
		{
			if(!add_number_to_stack(stack, numbers[i]))
				return(0);		
			free(numbers[i]);
			i++;
		}
		free(numbers);
		return(result);
	}
	else
	{
		return(add_number_to_stack(stack, arg));
	}
}
int	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				return (0);
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& !ft_isdigit(argv[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	process_single_argument(t_stack **stack, char *arg)
{
	char	**numbers;
	int		i;
	int		result;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	result = 1;
	while (numbers[i] && result == 1)
	{
		if (!add_number_to_stack(stack, numbers[i]))
			result = 0;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (result);
}

int	process_multiple_args(t_stack **stack, int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i < argc && result == 1)
	{
		if (!add_number_to_stack(stack, argv[i]))
			result = 0;
		i++;
	}
	return (result);
}
