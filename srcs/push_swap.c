/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:34 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/30 15:23:40 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	datafree(t_data *data)
{
	int	i;

	i = 0;
	if (data->intnb)
		free(data->intnb);
	while (data->charnb[i])
	{
		free(data->charnb[i]);
		i++;
	}
	free(data->charnb);
	free(data);
}

void	ft_free(t_data *data, t_list *lsta, t_list *lstb)
{
	if (data)
		datafree(data);
	if (lsta)
		lstfree(lsta);
	if (lstb)
		lstfree(lstb);
}

int	checklst(t_list *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int av, char **ac)
{
	t_list	*lista;
	t_list	*listb;
	t_data	*data;

	listb = NULL;
	if (av < 2)
		return (0);
	if (init(av, ac, &data, &lista) == 0)
		return (ft_free(data, lista, listb), write(1, "Error\n", 6), 0);
	if (checklst(lista) == 1)
		return (ft_free(data, lista, listb), 0);
	algo(data, &lista, &listb);
	return (ft_free(data, lista, listb), 0);
}
