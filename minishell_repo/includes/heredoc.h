#include "minishell.h"

#ifndef HEREDOC_H
# define HEREDOC_H

char	*expand_heredoc_line(char *line, t_shell *shell);
char	*read_heredoc_content(char *delimiter, int quoted, t_shell *shell);
t_cmd	*build_heredoc_cmd(t_token *tokens, t_shell *shell);
int		is_heredoc(t_token *tokens);
char	*heredoc_collect(char *delimiter, int quoted, t_shell *shell);
char	*read_all_fd(int fd);
void	ex_child(int write_fd, char *delimiter, int quoted, t_shell *shell);
char	*handle_heredoc_status(int status, char *content, t_shell *shell);

#endif
