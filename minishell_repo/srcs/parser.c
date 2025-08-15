#include "minishell.h" 

static int general_check(t_token *token_list);
static t_cmd *build_commands(t_token *token_listi, t_shell *shell);

t_cmd   *parse_tokens(t_token *token_list, t_shell *shell)
{
	(void)shell;
	t_token *current;
	current = token_list;

	if(current)
	{
		if(general_check(token_list))
		{	
			printf("no se genero token\n");
			return (NULL);
		}
		return (build_commands(token_list, shell));
	}
	return(NULL);
}

static int general_check(t_token *token_list)
{
	if (check_initial_token(token_list))
		return(1);
	if (check_all_redirections(token_list))
		return(1);
	if (check_all_pipe(token_list))	
		return(1);
	return(0);
}

t_cmd *build_commands(t_token *token_list, t_shell *shell)
{
	t_cmd *new_command;
	new_command = NULL;
	
	if (is_heredoc(token_list))
		new_command = (build_heredoc_cmd(token_list, shell));
	else if (has_redirections(token_list))
		new_command = build_command_with_redirections(token_list);
	else if(is_token_word(token_list) && token_list->next == NULL)
		new_command = one_word_command(token_list);
	else if(is_token_word(token_list) && token_list->next != NULL)
		new_command = words_plus_cmd(token_list);
	
	return(new_command);
}
/*
	printf("si se genero token\n");
	print_token_list(token_list);
	return(NULL);
}*/













