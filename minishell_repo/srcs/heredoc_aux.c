#include "minishell.h"

char    *expand_heredoc_line(char *line, t_shell *shell)
{
    return (build_expanded_string(line, shell));
}

int is_heredoc(t_token *tokens)
{
    t_token *current;

	current = tokens;
	while (current)
    {
        if (current->type == T_HEREDOC)
             return (1);
         current = current->next;
    }
    return (0);
}
