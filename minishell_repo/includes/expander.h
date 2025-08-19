#include "minishell.h"

#ifndef EXPANDER_H
# define EXPANDER_H

t_token	*expand_tokens(t_token *tokens, t_shell *shell);
t_token	*expander_ultra(t_token *tokens, t_shell *shell);
char	*find_var_value(char *var_name, t_shell *shell);
char	*build_expanded_string(char *original_str, t_shell *shell);
t_token	*split_to_tokens(char *str);
char	*ft_strjoin_and_free(char *s1, char *s2);
t_token	*finalize_and_join_tokens(t_token *list);

#endif 
