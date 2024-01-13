/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:16:04 by tburtin           #+#    #+#             */
/*   Updated: 2024/01/13 12:12:48 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_list
{
	int				donne;
	int				index;
	struct s_list	*suivant;
}t_list;

void	s(t_list **premiere_case, char c);
void	p(t_list **premiere_case_a, t_list **premiere_case_b, char c);
void	r(t_list **premiere_case, char c);
void	rr(t_list **premiere_case, char c);

void	ft_check_args(int argc, char **argv);
void	ft_error(int argc, char *args[]);
void	ft_free(char **str);
void	free_stack(t_list **stack);
void	ft_lstadd_back(t_list **stack, t_list *new);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
int		is_sorted(t_list **stack);
int		ft_lstsize(t_list *head);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
int		get_distance(t_list **stack, int index);
void	attribution_index(t_list **stack);
void	part2_sort_3(t_list **stack_a, t_list *head, int min);

long	ft_atoi(const char *str);
char	**ft_split(char const *str, char c);

#endif
