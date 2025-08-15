#include "minishell.h"

static void process_tokens(t_token *tokens, char *line, t_shell *shell);
int  handle_ctrl_c(char **line);

void	start_loop(t_shell *shell)
{
	char	*line;
	t_token *tokens;

	while (shell->running)
	{
		line = read_input();
		if (check_ctrl_d(line))
			break ;
		if (handle_ctrl_c_signal(&line))
		{
		}
		else
		{
			if (isatty(STDIN_FILENO) && history(line))
		    	add_history(line);
		    
			tokens = tokenize_line(line, shell);
			if(tokens)
			{
				process_tokens(tokens, line, shell);	 
			}
			else
				free(line);
		}
	}
}

int	handle_ctrl_c(char **line)
{
	g_signal = 0;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	free(*line);
	*line = NULL;
	return (1);
}

static void process_tokens(t_token *tokens, char *line, t_shell *shell)
{
    t_cmd *commands;
 	t_token *original_tokens;
	t_token *expanded_tokens;
	t_token *final_tokens;

	commands = NULL;
	
	/*printf("tokens originales \n");*/
	/*print_token_list(tokens);*/
	original_tokens = tokens;
    expanded_tokens = expand_tokens(original_tokens, shell);
	free_tokens(original_tokens);
    if (expanded_tokens)
	{
		final_tokens = finalize_and_join_tokens(expanded_tokens);
		free_tokens(expanded_tokens);
        commands = parse_tokens(final_tokens, shell);
	}
	else
		final_tokens = NULL;
    if (!commands)
    {
        shell->last_status = INVALID;
       /*printf("Build responde NULL, aun no implemento\n");*/
        free_everything(line, final_tokens, commands); 
        return;
    }
    execute_commands(commands, shell);
 /* printf("imprime token finales expan o no");*/
/*	print_token_list(final_tokens);*/ 
	free_everything(line, final_tokens, commands); 
}
