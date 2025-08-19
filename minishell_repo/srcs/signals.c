#include "minishell.h"
#include <sys/ioctl.h>

volatile sig_atomic_t	g_signal = 0;

void	signal_handler(int signo)
{
	g_signal = signo;
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
