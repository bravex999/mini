#include "minishell.h"

int check_initial_token(t_token *token_list)// error 1er Token no valid.        
{
	if(token_list->type == T_PIPE)
         return(1);
	if(token_list->type == T_WORD
		|| token_list->type == T_QUOTED_DOUBLE
		|| token_list->type == T_QUOTED_SINGLE)
		return(0);
	if((token_list->type == T_REDIR_IN || token_list->type == T_REDIR_OUT)
		&& token_list->next == NULL)
		return(1);
	if((token_list->type == T_REDIR_APPEND || token_list->type == T_HEREDOC)
		&& token_list->next == NULL)
		return(1);
	else
		return(0);
}

int check_all_redirections(t_token *token_list)
{
    t_token *current;
	current = token_list;

    while (current)
    {
        if (current->type >= T_REDIR_IN && current->type <= T_HEREDOC)
        {
            if (!current->next)
                return(1);
            if (current->next->type != T_WORD
                && current->next->type != T_QUOTED_SINGLE
                && current->next->type != T_QUOTED_DOUBLE)
                return(1);
        }
        current = current->next;
    }
    return(0);
}

int check_all_pipe(t_token *token_list)
{
	t_token *current;
	t_token *previous;

	previous = NULL;
	current = token_list;

	while(current)
	{
		if(previous != NULL
			&& previous->type == T_PIPE
			&& current->type == T_PIPE)
		return (1);
		if(current->type == T_PIPE && current->next == NULL)
			return (1);
		previous = current;
		current = current->next;
	}	
	return(0);
}
