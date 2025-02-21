/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidailas <walidailas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:25:25 by wailas            #+#    #+#             */
/*   Updated: 2025/02/05 15:50:24 by walidailas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int				size;
	t_node			*head;
}				t_stack;

/////////////// Functions related to stack initialization ///////////////

void	free_stack(t_stack *stack);
t_stack	*ft_lst_init(int content);
int		ft_lstsize_stack(t_node *head);
void	ft_lst_init_back(t_stack **lst, t_stack *lst2);
void	printf_stack(t_stack *stack, char *stack_name);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
int		pop_stack(t_stack *stack);
int		index_of(int n, int *arr);
void	insertion_sort(int array[], int n);
int		*convert_args_to_int(int argc, char **argv);
void	push_stack(t_stack *stack, int index, int data);
void	ft_check(t_stack *stack_a, t_stack *stack_b);
char	**allocate_result_array(int argc, char **argv, int *total_args);
char	**split_arguments(int argc, char **argv, int *new_argc);
void	free_split(char **split);
bool	ft_atoi_max(char *str);

///////////////////// Argument verification functions  ////////////////

int		ft_is_duplicate(int num, char **argv, int i);
int		ft_is_numeric(char *num);
void	verif_arg(int argc, char **argv);
void	ft_free(char **str);
int		is_sorted(t_stack *stack);
void	cleanup_args(void *data);
void	display_error(char *error_msg, void (*cleanup)(void*), void *data);
int		ft_sqrt(int number);
int		count_words(const char *str, char delimiter);
int		is_valid_number(char *str);

////////////////////////// Stack movement functions //////////////////////////

void	ft_push(t_stack *dest, t_stack *src, char name, bool print);
void	ft_rotate(t_stack *lst, char name, bool print);
void	ft_reverse_rotate(t_stack *lst, char name, bool print);
void	ft_swap(t_stack *lst, char name, bool print);
void	ft_reverse_rotate_both(t_stack *a, t_stack *b);
void	swap_both(t_stack *stack1, t_stack *stack2);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

//////////////////////////  Positioning functions  //////////////////////////

int		get_min_index(t_stack *stack);
int		count(t_node *stack, int index);

//////////////////////////  Utility functions //////////////////////////

int		count(t_node *stack, int index);

#endif
