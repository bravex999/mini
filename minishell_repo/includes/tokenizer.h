#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_token_type {
	T_WORD,
	T_QUOTED_DOUBLE,  
   	T_QUOTED_SINGLE,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}	t_token_type;

typedef struct s_token {
	char			*str;
	t_token_type	type;
	int				expand;
	int				join_next;
	int				quoted_del;
	struct s_token	*next;
}t_token;

t_token *create_token(t_token_type type, char *str);
t_token *tokenize_line(char *line,t_shell *shell);
t_token *handle_quotes(char *line, int *i, t_shell *shell);
t_token *redir_operators_app_her(char *line, int *i);
t_token *simple_redir(char *line, int *i);
t_token *words(char *line, int *i, t_shell *shell);
void	free_tokens(t_token *token_list);
void	 print_token_list(t_token *token_list); // funcion a eliminar es de debuggin
t_token *create_token_safe(t_token_type type, char *line_token);
void add_token(t_token **token_list, t_token *new);
t_token *handle_double(char *line, int *i, t_shell *shell);
t_token *handle_single(char *line, int *i);
int		is_token_word(t_token *token_list);
t_token	 *words_and_quotes(char *line, int *i, t_shell *shell);
char	 *handle_quotes_join(char *line, int *i, t_shell *shell);
char	 *handle_single_join(char *line, int *i);
char	 *handle_double_join(char *line, int *i, t_shell *shell);
char *words_join(char *line, int *i, t_shell *shell);


#endif
