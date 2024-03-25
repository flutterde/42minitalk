/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:07:10 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/22 15:48:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_data
{
	pid_t			sender;
	char			*msg;
	size_t			id;
	unsigned char	c;
	int				c_index;
	size_t			len;
	int				m_index;
}	t_data;

void	mini_printf(int fd, const char *str, ...);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_exit(int fd, int _status, char *msg);
void	ft_reset_val(t_data *data);

#endif