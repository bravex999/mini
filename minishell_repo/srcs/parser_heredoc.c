#include "minishell.h"

char	*read_all_fd(int fd)
{
	char	*res;
	char	buf[4096 + 1];
	ssize_t	n;
	char	*tmp;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	n = read(fd, buf, 4096);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(res, buf);
		free(res);
		if (!tmp)
			return (NULL);
		res = tmp;
		n = read(fd, buf, 4096);
	}
	return (res);
}


static int	process_all_heredocs(t_cmd *cmd, t_token *tokens, t_shell *shell)
{
	int		quoted;
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type == T_HEREDOC && current->next)
		{
			if (cmd->heredoc_delimiter)
				free(cmd->heredoc_delimiter);
			cmd->heredoc_delimiter = ft_strdup(current->next->str);
			if (cmd->heredoc_content)
				free(cmd->heredoc_content);
			if (current->next->type == T_QUOTED_SINGLE || current->next->type == T_QUOTED_DOUBLE)
				quoted = 1;
			else
				quoted = 0;
			cmd->heredoc_content = heredoc_collect(current->next->str, quoted, shell);
			if (!cmd->heredoc_content)
				return (1);
		}
		current = current->next;
	}
	return (0);
}

t_cmd	*build_heredoc_cmd(t_token *tokens, t_shell *shell)
{
	t_cmd	*cmd;
	t_token	*argv_tokens;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	if (process_all_heredocs(cmd, tokens, shell) != 0)
		return (free_commands(cmd), NULL);
	argv_tokens = filter_argv_tokens(tokens);
	cmd->argv = ultra_split(argv_tokens);
	free_tokens(argv_tokens);
	return (cmd);
}
