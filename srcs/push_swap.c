/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:47:34 by emoreau           #+#    #+#             */
/*   Updated: 2023/06/15 23:06:17 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_free(t_data *data, t_list *lsta, t_list *lstb)
{
	int	i;

	i = 0;
	free(data->intnb);
	while (data->charnb[i])
	{
		free(data->charnb[i]);
		i++;
	}
	free(data->charnb);
	while (lsta)
	{
		free(lsta);
		lsta = lsta->next;
	}
	free(lstb);
}

int	main(int av, char **ac)
{
	t_list	*lista;
	t_list	*listb;
	t_data	*data;

	if (av < 2)
		return (0);
	if (init(av, ac, &data, &lista, &listb) == 0)
		return (write(1, "error\n", 6), 0);
	algo(data, &lista, &listb);
	ft_free(data, lista, listb);
	// while (lista)
	// {
	// 	printf("%d\n", lista->value);
	// 	lista = lista->next;
	// }	
// 	while (*(data->intnb))
// 	{
// 		printf("%d\n", *(data->intnb));
// 		data->intnb++;
// 	}
// printf("mediane = %d\n", data->mediane);
// 	while (listb)
// 	{
// 		printf("%d\n", listb->value);
// 		listb = listb->next;
// 	}
// 	//test des fonctions de mouvement
// 	printf("\n\n\ntest des fonctions de mouvement\n\n\n");
// 	// t_list *lst;
// 	t_list *lst1;
// 	t_list *lst2;
// 	t_list *lst3;

// 	lst1 = malloc(sizeof(t_list));
// 	lst2 = malloc(sizeof(t_list));
// 	lst3 = malloc(sizeof(t_list));

// 	lst1->value = 1;
// 	lst2->value = 2;
// 	lst3->value = 3;

// 	lst1->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = NULL;
// 	rrr(&lst1, &lst1);
// 	// printf("%d\n", lst->value);
// 	while (lst1)
// 	{
// 		printf("%d\n", lst1->value);
// 		lst1 = lst1->next;
// 	}
return (0);
}