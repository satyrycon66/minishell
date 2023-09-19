/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:57:47 by alpicard          #+#    #+#             */
/*   Updated: 2023/09/19 18:32:08 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	no_cmds(char *input)
{
	int	x;
	int	y;
	int i = 0;
	x = 0;
	y = 1;
	while (input[i] && input )
	{
		if (input[i] == '<')
			y++;
		else if (input[i] == '>')
			y++;
		else if (input[i] == '|')
			y++;
		i++;

	}
	return (y);
}

int	no_args(char *input)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (input[i])
	{
		if (input[i - 1] == ' ' || i == 0)
		{
			if (!strncmp(&input[i], "ls ", 3))
			{
				write(1, "cmd found\n", 10);
				// x--;
			}
			else if (strncmp(&input[i], "ls ", 3) && i == 0)
			{
				write(1, "cmd not found\n", 14);
				return (-1);
			}
			else
			{
				// return (-1);
				x++;
			}
		}
		i++;
	}
	return (x);
}

int	main(int ac, char **av)
{
	printf("%d\n", no_cmds(av[1]));
	printf("%d\n", no_args(av[1]));
}