#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

// Headers internos del proyecto
# include "shell.h"  
# include "tokenizer.h" 
# include "parser.h"
# include "signals.h"  // de declara la variable global para manejo de señales.
# include "status.h"  //  aquí va un enum,  para errores etc.
# include "expander.h"
# include "executor.h"
# include "main_aux.h" // funciones auxiliares del main.c y main_aux.c
# include "built.h"
# include "free.h" 
# include "heredoc.h"
# include "path_resolver.h"
# include "redirections.h"

#endif
