/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:41:44 by transfo           #+#    #+#             */
/*   Updated: 2024/01/08 14:09:04 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void ft_error(char *message)
{
    printf("%s", message);
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

void	printList(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->donne);
		tmp = tmp->suivant;
	}
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