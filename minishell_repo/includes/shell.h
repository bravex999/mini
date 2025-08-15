#ifndef SHELL_H
# define SHELL_H

typedef struct s_shell {
	char			**envp;
	int				last_status;
	int				running;
	struct s_cmd	*cmds;
}					t_shell;

/* Inicializa el estado del shell */
void	init_shell(t_shell *shell, char **envp);

/* Libera los recursos del shell al terminar */
void	cleanup_shell(t_shell *shell);

#endif
