#ifndef STATUS_H
# define STATUS_H

typedef enum e_status
{
	EXIT_OK = 0,
	EXIT_KO = 1,
	INVALID = 2,
	CMD_NOT_EXECUTABLE = 126,
	UNKNOWN_COMMAND = 127,
	SIGINT_EXIT = 130,
}	t_status;

#endif
