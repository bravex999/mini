#include "minishell.h"

static int	save_stdin_if_needed(int *saved_stdin)
{
	if (saved_stdin && *saved_stdin == -1)
	{
		*saved_stdin = dup(STDIN_FILENO);
		if (*saved_stdin == -1)
			return (-1);
	}
	return (0);
}

static ssize_t	write_all_heredoc(int fd, const char *s)
{
	size_t	len;
	size_t	off;
	ssize_t	n;
	ssize_t	ret;

	len = ft_strlen(s);
	off = 0;
	while (off < len)
	{
		n = write(fd, s + off, len - off);
		if (n <= 0)
			break ;
		off += (size_t)n;
	}
	ret = (ssize_t)off;
	return (ret);
}

int	setup_heredoc_stdin(t_cmd *cmd, int *saved_stdin)
{
	int		p[2];
	size_t	len;
	ssize_t	off;

	if (!cmd->heredoc_content)
		return (0);
	if (save_stdin_if_needed(saved_stdin) == -1)
		return (-1);
	if (pipe(p) == -1)
		return (-1);
	len = ft_strlen(cmd->heredoc_content);
	off = write_all_heredoc(p[1], cmd->heredoc_content);
	close(p[1]);
	if (dup2(p[0], STDIN_FILENO) == -1)
	{
		close(p[0]);
		return (-1);
	}
	close(p[0]);
	free(cmd->heredoc_content);
	cmd->heredoc_content = NULL;
	if ((size_t)off < len)
		return (-1);
	return (0);
}
