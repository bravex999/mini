#include "minishell.h"
#include "minishell.h"

typedef struct s_join_data
{
	char	type_quote;
	int		count_quote;
	int		count_word;
}	t_join_data;

static int	join_token_part(char **final_token, char *part)
{
	char	*temp;

	if (!part)
	{
		free(*final_token);
		return (1);
	}
	temp = *final_token;
	*final_token = ft_strjoin(*final_token, part);
	free(temp);
	free(part);
	if (!*final_token)
		return (1);
	return (0);
}

static char	*get_part_and_update_counts(char *line, int *i, t_shell *shell, \
t_join_data *data)
{
	if (line[*i] == '\'' || line[*i] == '"')
	{
		data->type_quote = line[*i];
		data->count_quote++;
		return (handle_quotes_join(line, i, shell));
	}
	else
	{
		data->count_word++;
		return (words_join(line, i, shell));
	}
}

t_token	*words_and_quotes(char *line, int *i, t_shell *shell)
{
	t_join_data	data;
	char		*part;
	char		*final_token;

	data.count_word = 0;
	data.count_quote = 0;
	data.type_quote = 0;
	final_token = ft_strdup("");
	if (!final_token)
		return (NULL);
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t' && line[*i] != '|'
		&& line[*i] != '>' && line[*i] != '<')
	{
		part = get_part_and_update_counts(line, i, shell, &data);
		if (join_token_part(&final_token, part) != 0)
			return (NULL);
	}
	if (data.count_word == 0 && data.count_quote == 1)
	{
		if (data.type_quote == '"')
			return (create_token_safe(T_QUOTED_DOUBLE, final_token));
		return (create_token_safe(T_QUOTED_SINGLE, final_token));
	}
	return (create_token_safe(T_WORD, final_token));
}
