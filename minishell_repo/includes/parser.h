#include "minishell.h"

#ifndef PARSER_H
# define PARSER_H

typedef struct s_cmd
{
	char				**argv;
	char				*infile;
	char				*outfile;
	char				*heredoc_delimiter;
	char				*heredoc_content;
	int					append;
	int					pipe_in;
	int					pipe_out;
	struct s_cmd		*next;
}						t_cmd;

t_cmd   *parse_tokens(t_token *token_list, t_shell *shell);
int		check_initial_token(t_token *token_list);
int		check_all_redirections(t_token *token_list);
int		check_all_pipe(t_token *token_list);
char	**super_split(char const *s, char c, char b);
t_cmd	*one_word_command(t_token *token_list);
t_cmd	*words_plus_cmd(t_token *token_list); 
void    str_free(char **arr);
t_cmd	*build_heredoc_cmd(t_token *tokens, t_shell *shell);
int     has_redirections(t_token *token_list);
t_cmd   *build_command_with_redirections(t_token *token_list);
t_token *filter_argv_tokens(t_token *token_list);

#endif
