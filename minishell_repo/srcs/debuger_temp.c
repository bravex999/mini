#include "minishell.h"
void print_token_list(t_token *token_list)
{
    t_token *current;
    int i;
    
    i = 0;
    current = token_list;
    printf("=== TOKEN LIST ===\n");
    while (current)
    {
        printf("Token %d:\n", i++);
        printf("  Type: ");
        if (current->type == T_WORD)
            printf("T_WORD");
        else if (current->type == T_QUOTED_DOUBLE)
            printf("T_QUOTED_DOUBLE");
        else if (current->type == T_QUOTED_SINGLE)
            printf("T_QUOTED_SINGLE");
        else if (current->type == T_PIPE)
            printf("T_PIPE");
        else if (current->type == T_REDIR_IN)
            printf("T_REDIR_IN");
        else if (current->type == T_REDIR_OUT)
            printf("T_REDIR_OUT");
        else if (current->type == T_REDIR_APPEND)
            printf("T_REDIR_APPEND");
        else if (current->type == T_HEREDOC)
            printf("T_HEREDOC");
        printf("\n  String: '%s'\n", current->str);
		printf("\n  expand: '%d'\n", current->expand);
        current = current->next;
    }
    printf("==================\n\n");
}
