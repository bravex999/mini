#include "minishell.h"

#ifndef FREE_H
#define FREE_H

void	free_everything(char *line, t_token *tokens, t_cmd *cmds);
void	free_commands(t_cmd *command_list);

#endif

