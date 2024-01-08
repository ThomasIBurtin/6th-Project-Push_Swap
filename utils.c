/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:52:33 by transfo           #+#    #+#             */
/*   Updated: 2024/01/08 14:08:10 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->suivant != NULL)
	{
		tmp = tmp->suivant;
		if (tmp->suivant == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack != NULL)
	{
		n = ft_lstlast(*stack);
		n->suivant = new;
		new->suivant = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->suivant = NULL;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->donne = value;
	new->index = -1;
	new->suivant = NULL;
	return (new);
}

int	is_sorted(t_list **stack)
{
	t_list *head;

	head = *stack;
	while (head->suivant != NULL)
	{
		if (head->donne > head->suivant->donne)
			return (0);
		head = head->suivant;
	}
	return (1);
}