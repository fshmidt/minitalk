/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:42:31 by mbesan            #+#    #+#             */
/*   Updated: 2021/11/08 23:38:32 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

static void	ft_kill_zero(int pid)
{
	int	bytes;

	bytes = 0;
	while (8 - bytes++)
	{
		if (kill(pid, SIGUSR1) == -1)
			write(1, "Wrong PID, pid\n", 15), exit(0);
		usleep(300);
	}
}

static void	ft_kill(int pid, char *str)
{
	int		bytes;
	char	symbol;

	while (*str)
	{
		bytes = 8;
		symbol = *str++;
		while (bytes--)
		{
			if (symbol >> bytes & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					write(1, "Wrong PID, pid\n", 15), exit(0);
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					write(1, "Wrong PID, pid\n", 15), exit(0);
			usleep(300);
		}
	}
	ft_kill_zero(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(1, "Wrong arguments\n", 16);
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		write(1, "PID is a number lol\n", 20);
	act.sa_handler = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
