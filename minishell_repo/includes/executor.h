#include "minishell.h"

#ifndef EXECUTOR_H
#define EXECUTOR_H

void    execute_commands(t_cmd *commands, t_shell *shell);
int		ft_strcmp(char *s1, char *s2);
char	**ultra_split(t_token *token_list);
void execute_builtin(t_cmd *cmd, t_shell *shell);
int	setup_heredoc_stdin(t_cmd *cmd, int *saved_stdin);
void	restore_stdin_from_saved(int *saved_stdin);
void	 run_external(t_cmd *cmd, t_shell *shell);
int	  is_builtin(char *cmd);

#endif
