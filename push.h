/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:16:04 by tburtin           #+#    #+#             */
/*   Updated: 2024/01/08 14:18:44 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				donne;
	int				index;
	struct s_list	*suivant;
}t_list;


void	s(t_list **premiere_case);
void	p(t_list **premiere_case_a, t_list **premiere_case_b);
void	r(t_list **premiere_case);
void	rr(t_list **premiere_case);

void	ft_check_args(int argc, char **argv);
void ft_error(char *message);
void	ft_free(char **str);
void free_stack(t_list **stack);
void	ft_lstadd_back(t_list **stack, t_list *new);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	printList(t_list *head);
int	is_sorted(t_list **stack);
int	ft_lstsize(t_list *head);
void radix_sort(t_list **stack_a, t_list **stack_b);
void simple_sort(t_list **stack_a, t_list **stack_b);

int	ft_atoi(const char *str);
char	**ft_split(char const *str, char c);

#endif
