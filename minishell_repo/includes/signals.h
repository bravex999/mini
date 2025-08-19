#include "minishell.h"

#ifndef SIGNALS_H
# define SIGNALS_H

extern volatile sig_atomic_t	g_signal;
void	setup_signals(void);
void	signal_handler(int signo);

#endif
