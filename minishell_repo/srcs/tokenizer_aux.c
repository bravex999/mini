#include "minishell.h"

t_token *handle_quotes(char *line, int *i, t_shell *shell)
{
    (void)shell;
	t_token *line_token;

	if (line[*i] == '"')
      line_token = handle_double(line, i, shell); 
    else
		line_token = handle_single(line, i);
	return(line_token);	
}

t_token  *redir_operators_app_her(char *line, int *i)
{
	char *line_token;
	t_token *new_token;
	new_token = NULL;

	line_token = ft_substr(line, *i, 2);
	if(!line_token)
		return (NULL);
    if (line[*i + 1] == '>')
		new_token = create_token_safe(T_REDIR_APPEND, line_token);
	else if(line[*i + 1] == '<')
		new_token = create_token_safe(T_HEREDOC, line_token);
	*i += 2;
	return(new_token);
}

t_token *simple_redir(char *line, int *i)
{
	t_token *new_token;
	char *line_token;
	new_token = NULL;
	
	line_token = ft_substr(line, *i, 1);
	if(!line_token)
		return (NULL);
	if (line[*i] == '|')
		new_token = create_token_safe(T_PIPE, line_token);
	else if (line[*i] == '<')
		new_token = create_token_safe(T_REDIR_IN, line_token);
	else if(line[*i] == '>')
		new_token = create_token_safe(T_REDIR_OUT, line_token);
	(*i)++;
	return(new_token);
}

t_token *words(char *line, int *i, t_shell *shell)
{
    (void)shell;
	int start_word;
    char *line_token;
    int len;
  /*char *expand_line;*/
  
     len = 0;
     start_word = *i;
     while(line[*i] && line[*i] != ' ' && line[*i] != '"' && line[*i] != '\'' &&
                   line[*i] != '|' && line[*i] != '>' && line[*i] != '<')
     {
         len++;
         (*i)++;
     }
     line_token = ft_substr(line, start_word, len);
     if(!line_token)
         return (NULL);
    /* if(ft_strchr(line_token, '$'))
     {
         expand_line = expander(line_token, shell);
         free(line_token);
         return(expand_split(expand_line));
     }*/   
     return(create_token_safe(T_WORD, line_token));
}

