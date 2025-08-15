#include "minishell.h"

t_token *create_token_safe(t_token_type type, char *line_token)
{
    t_token *token;

    token = create_token(type, line_token);
    if (!token)
    {
        free(line_token);
        return (NULL);
    }
    if (type != T_QUOTED_SINGLE && ft_strchr(token->str, '$'))
        token->expand = 1;
    else
        token->expand = 0;
    return (token);
}

t_token	*create_token(t_token_type type, char *str)
{
	t_token	*token;

	token = NULL;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
	token->next = NULL;
	token->expand = 0;
	token->join_next = 0;
	token->quoted_del = 0;
	return (token);
}

void	add_token(t_token **token_list, t_token *new)
{
	t_token	*current;

	if (*token_list == NULL)
	{
		*token_list = new;
		return ;
	}
	current = *token_list;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_tokens(t_token *token_list)
{
	t_token	*current;
	t_token	*next;

	current = token_list;
	while (current)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}

/*static t_token *create_single_token(char *line, int *i, t_shell *shell)
{
    t_token *new_token;
    
    if (line[*i] == line[*i + 1] && (line[*i] == '>' || line[*i] == '<'))
    {
        new_token = redir_operators_app_her(line, i);
        if (new_token && new_token->type == T_HEREDOC)
        {
            int temp_i = *i;
            while (line[temp_i] && (line[temp_i] == ' ' || line[temp_i] == '\t'))
                temp_i++;
            if (line[temp_i] == '\'' || line[temp_i] == '"')
                new_token->quoted_del = 1;
            else
                new_token->quoted_del = 0;
        }
    }   
    else if (line[*i] == '|' || line[*i] == '>' || line[*i] == '<')
        new_token = simple_redir(line, i);
    else if (line[*i] == '"' || line[*i] == '\'')
        new_token = handle_quotes(line, i, shell);
    else 
        new_token = words(line, i, shell);
    
    return (new_token);
}


t_token *tokenize_line(char *line, t_shell *shell)
{
    t_token *token_list;
    t_token *new_token;
    int     i;

    token_list = NULL;
    i = 0;
    while (line[i])
    {
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if (line[i] == '\0')
            break ;
        
        new_token = create_single_token(line, &i, shell);
        if (!new_token) 
            return (free_tokens(token_list), NULL);
        
        new_token->join_next = 0;
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
            new_token->join_next = 1;
        add_token(&token_list, new_token);
    }   
    return (token_list);
}*/

t_token *tokenize_line(char *line, t_shell *shell)
{
	t_token *token_list;
	t_token *new_token;
	int		i;

	token_list = NULL;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0')
			break ;
		if (line[i] == line[i + 1] && (line[i] == '>' || line[i] == '<'))
		{
			new_token = redir_operators_app_her(line, &i);
			if (new_token && new_token->type == T_HEREDOC)
			{
				int temp_i = i;
				while (line[temp_i] && (line[temp_i] == ' ' || line[temp_i] == '\t'))
					temp_i++;
				if (line[temp_i] == '\'' || line[temp_i] == '"')
					new_token->quoted_del = 1;
				else
					new_token->quoted_del = 0;
			}
		}
		else if (line[i] == '|' || line[i] == '>' || line[i] == '<')
			new_token = simple_redir(line, &i);
		else if (line[i] == '"' || line[i] == '\'')
			new_token = handle_quotes(line, &i, shell);
		else
			new_token = words(line, &i, shell);
		if (!new_token)
			return (free_tokens(token_list), NULL);
		new_token->join_next = 0;
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
			new_token->join_next = 1;
		add_token(&token_list, new_token);
	}
/*	printf("lista 1 creada");*/
	return (token_list);
}
