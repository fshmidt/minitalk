/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:42:31 by mbesan            #+#    #+#             */
/*   Updated: 2021/11/09 17:53:41 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	sig_handler(int sig)
{
	static int	got = 0;

	if (sig == SIGUSR2)
		got++;
	else
	{
		ft_putnbr_fd(got, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

static void	ft_kill_zero(int pid)
{
	int	bytes;

	bytes = 0;
	while (8 - bytes++)
	{
		if (kill(pid, SIGUSR1) == -1)
			write(1, "\nWrong PID, pid\n", 16), exit(0);
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
					write(1, "\nWrong PID, pid\n", 16), exit(0);
			}
			else
				if (kill(pid, SIGUSR1) == -1)
					write(1, "\nWrong PID, pid\n", 16), exit(0);
			usleep(300);
		}
	}
	ft_kill_zero(pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(1, "Wrong arguments\n", 16);
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		write(1, "PID is a number lol\n", 20);
	write(1, "Out: ", 5);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	write(1, "\n", 1);
	write(1, "In: ", 4);
	s_sigaction.sa_handler = sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
