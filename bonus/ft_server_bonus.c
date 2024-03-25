/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:02:29 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	alloc_handler(int nbr)
{
	if (nbr <= 0)
		ft_reset_val(&g_data);
	g_data.msg = ft_calloc((g_data.len) + 1, 1);
	if (!g_data.msg)
		ft_reset_val(&g_data);
}

static void	process_msg_data(int signum)
{
	if (g_data.c_index < 8)
	{
		if (signum == SIGUSR1)
			g_data.c = (g_data.c << 1);
		else
			g_data.c = (g_data.c << 1) | 1;
		g_data.c_index++;
	}
	if (g_data.c_index == 8)
	{
		g_data.msg[g_data.m_index++] = g_data.c;
		g_data.c = 0;
		g_data.c_index = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *con)
{
	(void) con;
	if (g_data.sender != 0 && (g_data.sender != info->si_pid))
		ft_reset_val(&g_data);
	else if (g_data.sender == 0)
		g_data.sender = info->si_pid;
	if (g_data.id == 32)
		alloc_handler(g_data.len);
	if (g_data.id < 32 && (signum == SIGUSR1 || signum == SIGUSR2))
	{
		if (signum == SIGUSR1)
			g_data.len = (g_data.len << 1);
		else
			g_data.len = (g_data.len << 1) | 1;
	}
	else if (g_data.id >= 32 && (signum == SIGUSR1 || signum == SIGUSR2))
		process_msg_data(signum);
	g_data.id++;
	if (g_data.id == ((g_data.len * 8) + 32))
	{
		mini_printf(1, "%s\n", g_data.msg);
		kill(g_data.sender, SIGUSR2);
		ft_reset_val(&g_data);
	}
}

int	main(void)
{
	struct sigaction	sa;

	mini_printf(1, "The Server PID: %d.\n", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
