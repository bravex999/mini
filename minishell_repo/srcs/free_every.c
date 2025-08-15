#include "minishell.h"

void	free_everything(char *line, t_token *tokens, t_cmd *cmds)
{
	if(line)
		free(line);
	if(tokens)
		free_tokens(tokens);
	if(cmds)
		free_commands(cmds);
}

void free_commands(t_cmd *command_list)
{
    t_cmd *current;
    t_cmd *next;

    current = command_list;
    while(current)
    {
        next = current->next;
        if (current->argv)
            str_free(current->argv);
        if(current->infile)
            free(current->infile);
        if(current->outfile)
            free(current->outfile);
        if(current->heredoc_delimiter)
            free(current->heredoc_delimiter);
        if(current->heredoc_content)
            free(current->heredoc_content);
        free(current);
        current = next;
    }
}
