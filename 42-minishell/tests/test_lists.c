/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:15:43 by alpicard          #+#    #+#             */
/*   Updated: 2023/09/19 17:32:12 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char			*cmd;
	// char			*arg;
	struct s_cmd	*next;
}					t_cmd;

t_cmd	*ft_lstlast(t_cmd *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lst_add_back(t_cmd **cmd, t_cmd *neo)
{
	t_cmd	*temp;

	if (*cmd == NULL)
		*cmd = neo;
	else
	{
		temp = ft_lstlast(*(cmd));
		temp->next = neo;
	}
}

t_cmd	*ft_lstnew(void *content)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->cmd = content;
	new_cmd->next = NULL;
	return (new_cmd);
}

int	main(int ac, char **av)
{
	t_cmd *temp;
	int x = 1;
	t_cmd *cmd;
	t_cmd *print;
	cmd = ft_lstnew(av[x]);
	if (ac == 1)
		return 0;
	while (av[x++])
	{
		temp = ft_lstnew(av[x]);
		ft_lst_add_back(&cmd, temp);
	}
	temp = cmd;
	while (temp->next != NULL)
	{
		printf("%s\n", temp->cmd);
		temp = temp->next;
	}
}