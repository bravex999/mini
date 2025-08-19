#include "minishell.h"

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

int		setup_input_redirection(t_cmd *cmd, int *saved_stdin);
int		setup_output_redirection(t_cmd *cmd, int *saved_stdout);
void	restore_redirections(int *saved_stdin, int *saved_stdout);

#endif
