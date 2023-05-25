# include "../includes/push_swap.h"

// int	listinit

int nbverif(char *nb)
{
	int	i;

	i = 0;
	while (i < ft_strlen(nb))
	{
		if (ft_isdigit(nb[i]) == 0 && nb[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	tab_nbverif(int av, char **ac)
{
	int	i;

	i = 1;
	while (i < av)
	{
		if (nbverif(ac[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*nbcat(int av, char **ac)
{
	char	*str;
	int		i;

	i = 2;
	str = ac[1];
	while (i < av)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ac[i]);
		i++;
	}
	return (str);
}

int	strllen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*atotab(char **nbr)
{
	int	*nb;
	int	i;

	i = 0;
	nb = malloc(sizeof(int) * strllen(nbr));
	if (!nb)
		return (NULL);
	while (nbr[i])
	{
		nb[i] = ft_atoi(nbr[i]);
		i++;
	}
	return (nb);
}

int	*getint(int av, char **ac, t_data **data)
{
	char 	*nb;
	char 	**nbr;
	int		*nombre;

	nb = nbcat(av, ac);
	nbr = ft_split(nb, ' ');
	nombre = atotab(nbr);
	(*data)->nbnb = strllen(nbr);
	return (nombre);
}

t_list *getlst(int *nb)
{
	t_list	*lsta;
	t_list	*tmp;
	int	i;

	i = 1;
	lsta = lstnewint(nb[0]);
	while (nb[i])
	{
		tmp = lstnewint(nb[i]);
		ft_lstadd_back(&lsta, tmp);
		i++;
	}
	return (lsta);
}

t_list	*pars(int av, char **ac, t_data **data)
{
	int	*nb;

	if (tab_nbverif(av, ac) == 0)
		return (0);
	nb = getint(av, ac, data);
	return(getlst(nb));
}

int	main(int av, char **ac)
{
	t_list	*lsta;
	t_data	*data;

	if (av < 2)
		return (0);
	lsta = pars(av, ac, &data);
	while (lsta->next)
	{
		printf("%d\n", lsta->value);
		lsta = lsta->next;
	}
return (0);
}