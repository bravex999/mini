#include "minishell.h"

static int	get_len_double(char *line, int *i);

t_token	*handle_double(char *line, int *i, t_shell *shell)
{
	int		len;
	int		start_word;
	char	*line_token;

	(void)shell;
	start_word = ++(*i);
	len = get_len_double(line, i);
	if (line[*i] && line[*i] == '"')
	{
		(*i)++;
		line_token = ft_substr(line, start_word, len);
		if (!line_token)
			return (NULL);
		return (create_token_safe(T_QUOTED_DOUBLE, line_token));
	}
	write(STDERR_FILENO, "minishell: syntax error: unclosed quote\n", 41);
	return (NULL);
}

t_token	*handle_single(char *line, int *i)
{
	int		len;
	int		start_word;
	char	*line_token;

	len = 0;
	start_word = ++(*i);
	while (line[*i] && line[*i] != '\'')
	{
		len++;
		(*i)++;
	}
	if (line[*i] == '\'')
	{
		(*i)++;
		line_token = ft_substr(line, start_word, len);
		if (!line_token)
			return (NULL);
		return (create_token_safe(T_QUOTED_SINGLE, line_token));
	}
	write(STDERR_FILENO, "minishell: syntax error: unclosed quote\n", 41);
	return (NULL);
}

static int	get_len_double(char *line, int *i)
{
	int	len;

	len = 0;
	while (line[*i] && line[*i] != '"')
	{
		len++;
		(*i)++;
	}
	return (len);
}
