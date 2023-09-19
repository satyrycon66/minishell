/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:39:24 by alpicard          #+#    #+#             */
/*   Updated: 2023/09/19 18:59:32 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	get_paths(t_minishell *minishell)
{
	int	x;

	x = 0;
	while (ft_strncmp(minishell->env[x], "PATH=", 5))
		x++;
	minishell->paths = ft_split(&(minishell->env[x])[5], ':');
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *input;
	t_minishell minishell;

	if (ac > 1)
		return (0);
	minishell.env = env;
	// get_paths(&minishell);


	//While 1 ???
	while (1)
	{
		input = readline("Minishell-1.0$ ");
		if (!parser(input, &minishell))
		{
			ft_printf("Minishell: %s: command not found\n", input);// 
			free(input);
			return (0) ; /// remove
		}
		add_history(input);

		// Do stuff...

		free(input);
	}
	return (0);
}