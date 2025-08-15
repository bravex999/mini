#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>

extern volatile sig_atomic_t	g_signal; // Variable global que almacena la señal recibida 
void	setup_signals(void); // Configura el comportamiento de las señales 
void signal_handler(int signo);

#endif
