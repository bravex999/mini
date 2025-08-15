#include "minishell.h"

int has_redirections(t_token *token_list)
{
    t_token *current;

    current = token_list;
    while (current)
    {
        if (current->type == T_REDIR_IN ||
            current->type == T_REDIR_OUT ||
            current->type == T_REDIR_APPEND)
            return (1);
        current = current->next;
    }
    return (0);
}
