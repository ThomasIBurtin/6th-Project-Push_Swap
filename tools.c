/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:41:44 by transfo           #+#    #+#             */
/*   Updated: 2024/01/12 17:30:35 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_error(char *message, int argc, char *args[])
{
	printf("%s", message);
	if (argc == 2)
		ft_free(args);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head != NULL)
	{
		tmp = head;
		head = head->suivant;
		free(tmp);
	}
	free(stack);
}

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->suivant;
		i++;
	}
	return (i);
}

void	part2_sort_3(t_list **stack_a, t_list *head, int min)
{
	if (head->suivant->index == min)
		r(stack_a, 'a');
	else
	{
		s(stack_a, 'a');
		rr(stack_a, 'a');
	}
}
