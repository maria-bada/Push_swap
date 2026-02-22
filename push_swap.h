/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:26:00 by mabada-r          #+#    #+#             */
/*   Updated: 2025/12/11 18:12:56 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int				value;
    int				index;
    struct s_node	*next;
    struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// Parsing functions
t_stack				*parse_arguments(int argc, char **argv);
int					process_combined_args(t_stack **stack, char *arg);
int					validate_arguments(int argc, char **argv);
int					process_single_argument(t_stack **stack, char *arg);
int					process_multiple_args(t_stack **stack, int argc,
						char **argv);
int					add_number_to_stack(t_stack **stack, char *str_num);
int					is_valid_integer(char *str);
int					is_duplicate(t_stack *stack, int num);
long				ft_atol(const char *str);

/* Sorting functions */
int					is_sorted(t_stack *stack);
int					find_smallest_position(t_stack *stack);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				push_smallest_to_b(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				push_two_smallest_to_b(t_stack *a, t_stack *b);
void				push_back_sorted(t_stack *a, t_stack *b);

/* K-sort Algorithm */
void				index_stack(t_stack *stack);
void				k_sort(t_stack *a, t_stack *b);
void				push_all_save_three(t_stack *a, t_stack *b, int size);
void				shift_stack(t_stack *a, t_stack *b);
int					get_chunk_size(int size);
int					get_target(t_stack *stack, int chunk_index, int range);
int					find_max_index_node(t_stack *stack);
int					get_position(t_stack *stack, t_node *node);
int					get_cost_rotate(t_stack *stack, int pos);
void				rotate_to_position(t_stack *stack, int pos, char name);

// Stack utils
t_stack				*create_stack(void);
t_node				*create_node(int value);
void				add_node_to_end(t_stack **stack, t_node *new_node);
void				free_stack(t_stack **stack);

// Operations
void				sa(t_stack *a, int print);
void				sb(t_stack *b, int print);
void				ss(t_stack *a, t_stack *b, int print);
void				pa(t_stack *a, t_stack *b, int print);
void				pb(t_stack *a, t_stack *b, int print);
void				ra(t_stack *a, int print);
void				rb(t_stack *b, int print);
void				rr(t_stack *a, t_stack *b, int print);
void				rra(t_stack *a, int print);
void				rrb(t_stack *b, int print);
void				rrr(t_stack *a, t_stack *b, int print);

// Libft functions
int					ft_isdigit(int c);
int					ft_strchr(const char *s, int c);
char				**ft_split(char const *s, char c);
int					ft_sqrt(int number);

#endif