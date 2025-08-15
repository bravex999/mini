#include "minishell.h"

static int	process_heredoc_line(char **full_content, char *line, int quoted, t_shell *shell)
{
	char	*temp_join;
	char	*temp_line;

	if (!quoted)
	{
		temp_line = expand_heredoc_line(line, shell);
		free(line);
		line = temp_line;
	}
	temp_join = ft_strjoin(*full_content, line);
	free(*full_content);
	if (!temp_join)
	{
		free(line);
		return (1);
	}
	*full_content = ft_strjoin(temp_join, "\n");
	free(temp_join);
	free(line);
	if (!*full_content)
		return (1);
	return (0);
}

char	*read_heredoc_content(char *delimiter, int quoted, t_shell *shell)
{
	char	*line;
	char	*full_content;

	full_content = ft_strdup("");
	if (!full_content)
		return (NULL);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (process_heredoc_line(&full_content, line, quoted, shell) != 0)
			return (NULL);
	}
	return (full_content);
}
