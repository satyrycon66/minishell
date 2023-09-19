/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_std_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:50:26 by alpicard          #+#    #+#             */
/*   Updated: 2023/09/19 17:14:08 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_args(va_list args, char **input)
{
	if (!strcmp(input[0], "ls"))
		printf("%s\n", input[1]);
	return (1);
}

int ft_store_args(char **input, ...)
{
	va_list args;
	int x = 0;
	va_start(args, input);
	while (input[x])
	{
		if (input[x] != NULL)
			ft_args(args, &input[x]);
		else
		 	return (0);
		x++;
	}
	va_end(args);
	return (1);
}

int main(int ac, char **av)
{
	char *argus;
	ft_store_args(av, argus);
}