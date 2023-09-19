/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 07:23:52 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/10 18:54:08 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (str)
	{
		while (*s1)
		{
			str[i++] = *s1++;
		}
		str[i] = 0;
	}
	return (str);
}
