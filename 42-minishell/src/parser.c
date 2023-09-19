/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:09:36 by alpicard          #+#    #+#             */
/*   Updated: 2023/09/19 19:05:21 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
The Command Table
The Command Table is an array of  SimpleCommand structs. 
A SimpleCommand struct contains members for the command and arguments of a 
single entry in the pipeline. The parser will look also at the command line 
and determine if there is any input or output redirection based on symbols 
present in the command (i.e. < infile, or > outfile).   
*/
/*
Your shell must implement the following builtins:
	echo with option -n
	cd with only a relative or absolute path
	pwd with no options
	export with no options
	unset with no options
	env with no options or arguments
	exit with no options
*/

typedef struct s_command
{
	char				*command;
	char				*args;
	struct s_command	*next;
	struct s_command	*prev;
}						t_command;

int	parser(char *input, t_minishell *mini)
{
	int no_wrds = 0; 
	// if (!input || !input[0]) // error
	// 	return (0); // error
	mini->split_input = ft_split(input, ' ');
	while (mini->split_input[no_wrds] != NULL && mini->split_input[no_wrds][0] != '<'
		&& mini->split_input[no_wrds][0] != '>' && mini->split_input[no_wrds][0] != '|')
	{
		no_wrds++;
	}
	mini->no_words = no_wrds;
	return (1);
}