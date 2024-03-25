/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:02:25 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:04 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	_send_char(int pid, unsigned char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			kill(pid, SIGUSR2);
			c -= i;
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i /= 2;
		usleep(200);
	}
}

static void	_sendlen(int pid, int len)
{
	char	*_len;
	int		i;

	i = 3;
	_len = (char *)&len;
	while (i >= 0)
	{
		_send_char(pid, _len[i]);
		i--;
	}
}

void	_handle_receive(int signum)
{
	if (signum == SIGUSR2)
		ft_exit(1, 0, "The Message Received By The Server.\n");
}

static void	_handler(int pid, char *msg)
{
	int	i;

	i = ft_strlen(msg);
	if (!i)
		return ;
	_sendlen(pid, i);
	i = 0;
	while (msg[i])
		_send_char(pid, msg[i++]);
}

int	main(int ac, char **av)
{
	int	s_pid;

	if (ac != 3)
		ft_exit(2, 1, "Missing argument, You have\
		 to enter 2 args (Server PID & Your Message)\n");
	s_pid = ft_atoi(av[1]);
	if (s_pid <= 2)
		ft_exit(2, 1, "Invalid PID!\n");
	signal(SIGUSR2, _handle_receive);
	_handler(s_pid, av[2]);
	while (1)
		pause();
	return (0);
}
