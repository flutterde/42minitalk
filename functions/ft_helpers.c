/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:41:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/21 21:43:18 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	s;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
		res = res * 10 + (str[i++] - 48);
	return (res * s);
}

void	ft_exit(int fd, int _status, char *msg)
{
	mini_printf(fd, "%s", msg);
	exit(_status);
}
