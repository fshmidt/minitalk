/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:44:48 by mbesan            #+#    #+#             */
/*   Updated: 2021/11/08 18:25:47 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int				bytes;
	static unsigned char	symbol;

	(void)context;
	symbol |= (signum == SIGUSR2);
	if (++bytes == 8)
	{
		bytes = 0;
		if (!symbol)
		{
			kill(siginfo->si_pid, SIGUSR1);
			return ;
		}
		ft_putchar_fd(symbol, 1);
		symbol = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
	else
		symbol <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
