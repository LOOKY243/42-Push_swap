/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:58:54 by gmarre            #+#    #+#             */
/*   Updated: 2024/01/07 16:20:55 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	int		*stack_a;
	int		*stack_b;
	int		a_pos;
	int		b_pos;
}			t_stacks;

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE 1
# define FALSE 0

int			ft_printf(const char *format, ...);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_strlen(char const *str);
int			ft_putunsigned(unsigned int n);
int			ft_base_sixteen(char arg, unsigned int n);
int			ft_which_printf(char format, va_list args);
int			ft_void_sixteen(unsigned long nb);
char		**ft_split(const char *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
int			get_args(char **av, t_stacks *stacks);
void		free_all(t_stacks *stacks);
int			arr_len(int *arr);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		find_best_push_to_b(t_stacks *stacks);
void		find_best_push_to_a(t_stacks *stacks);
int			count_swaps(t_stacks *stacks, int b_pos, int a_pos);
void		sort_a(t_stacks *stacks);
int			find_max(int *stack, int size);
int			find_min(t_stacks *stacks);
void		a_to_b(t_stacks *stacks);
void		b_to_a(t_stacks *stacks);
int			count_splits(char **str);
long int	ft_atoi(const char *nptr);
void		push_top_b(t_stacks *stacks);
void		push_top_a(t_stacks *stacks);
int			return_errors(void);
int			find_digit(char *str);
#endif
