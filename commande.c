/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:33:24 by tburtin           #+#    #+#             */
/*   Updated: 2024/01/13 12:13:28 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	s(t_list **premiere_case, char c)
{
	t_list	*deuxieme;

	deuxieme = (*premiere_case)->suivant;
	(*premiere_case)->suivant = deuxieme->suivant;
	deuxieme->suivant = *premiere_case;
	*premiere_case = deuxieme;
	if (c == 'a')
		ft_printf("%s", "sa\n");
	if (c == 'b')
		ft_printf("%s", "sb\n");
}

void	p(t_list **premiere_case_a, t_list **premiere_case_b, char c)
{
	t_list	*sauvegarde;

	sauvegarde = (*premiere_case_a)->suivant;
	(*premiere_case_a)->suivant = *premiere_case_b;
	*premiere_case_b = *premiere_case_a;
	*premiere_case_a = sauvegarde;
	if (c == 'a')
		ft_printf("%s", "pa\n");
	if (c == 'b')
		ft_printf("%s", "pb\n");
}

void	r(t_list **premiere_case, char c)
{
	t_list	*dernier;

	dernier = *premiere_case;
	while ((dernier)->suivant != NULL)
		dernier = dernier->suivant;
	dernier->suivant = *premiere_case;
	*premiere_case = (*premiere_case)->suivant;
	dernier = dernier->suivant;
	dernier->suivant = NULL;
	if (c == 'a')
		ft_printf("%s", "ra\n");
	if (c == 'b')
		ft_printf("%s", "rb\n");
}

void	rr(t_list **premiere_case, char c)
{
	t_list	*dernier;
	t_list	*avant_dernier;

	dernier = *premiere_case;
	avant_dernier = *premiere_case;
	while (avant_dernier->suivant->suivant != NULL)
		avant_dernier = avant_dernier->suivant;
	while ((dernier)->suivant != NULL)
		dernier = dernier->suivant;
	dernier->suivant = *premiere_case;
	*premiere_case = dernier;
	avant_dernier->suivant = NULL;
	if (c == 'a')
		ft_printf("%s", "rra\n");
	if (c == 'b')
		ft_printf("%s", "rrb\n");
}
