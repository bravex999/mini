#include "minishell.h"

char	*find_var_value(char *var_name, t_shell *shell);
char	*build_expanded_string(char *original_str, t_shell *shell);
t_token	*split_to_tokens(char *str);
char	*ft_strjoin_and_free(char *s1, char *s2);

static void	set_join_next_on_last(t_token *list, int join_next)
{
	t_token	*last;

	if (!list || !join_next)
		return ;
	last = list;
	while (last->next)
		last = last->next;
	last->join_next = join_next;
}

t_token	*expander_ultra(t_token *token, t_shell *shell)
{
	char	*expanded_str;
	t_token	*new_token_list;

	expanded_str = build_expanded_string(token->str, shell);
	if (expanded_str == NULL)
		return (NULL);
	if (token->type == T_QUOTED_DOUBLE)
	{
		new_token_list = create_token_safe(T_WORD, expanded_str);
		if (new_token_list)
			new_token_list->join_next = token->join_next;
	}
	else
	{
		new_token_list = split_to_tokens(expanded_str);
		set_join_next_on_last(new_token_list, token->join_next);
		free(expanded_str);
	}
	return (new_token_list);
}

t_token	*split_to_tokens(char *str)
{
	char	**words;
	t_token	*list;
	int		i;

	words = ft_split(str, ' ');
	if (!words)
		return (NULL);
	list = NULL;
	i = 0;
	while (words[i])
	{
		add_token(&list, create_token_safe(T_WORD, words[i]));
		i++;
	}
	free(words);
	return (list);
}

char	*find_var_value(char *var_name, t_shell *shell)
{
	int		i;
	int		len;

	if (!var_name || *var_name == '\0')
		return ("$");
	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(shell->last_status));
	i = 0;
	len = ft_strlen(var_name);
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], var_name, len) == 0
			&& shell->envp[i][len] == '=')
		{
			return (shell->envp[i] + len + 1);
		}
		i++;
	}
	return ("");
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (new_str);
}
