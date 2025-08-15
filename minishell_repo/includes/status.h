#ifndef STATUS_H
# define STATUS_H

typedef enum e_status
{
	EXIT_OK = 0,// Comando ejecutado correctamente
	EXIT_KO = 1,// Falla general
	INVALID = 2,// Error de sintaxis u otro uso inválido
	CMD_NOT_EXECUTABLE = 126,// Comando encontrado pero no ejecutable
	UNKNOWN_COMMAND = 127,// Comando no encontrado
	SIGINT_EXIT = 130,          // Ctrl+C recibido (SIGINT → 128 + 2)
}	t_status;

#endif
