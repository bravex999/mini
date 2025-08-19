#include "minishell.h"

void	ex_child(int write_fd, char *delimiter, int quoted, t_shell *shell)
{
	char	*buf;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	buf = read_heredoc_content(delimiter, quoted, shell);
	if (buf)
	{
		write(write_fd, buf, ft_strlen(buf));
		free(buf);
		exit(0);
	}
	exit(130);
}

char	*handle_heredoc_status(int status, char *content, t_shell *shell)
{
	if ((WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		|| (WIFEXITED(status) && WEXITSTATUS(status) == 130))
	{
		write(STDOUT_FILENO, "\n", 1);
		if (content)
			free(content);
		shell->last_status = 130;
		g_signal = 0;
		return (NULL);
	}
	return (content);
}

char	*heredoc_collect(char *delimiter, int quoted, t_shell *shell)
{
	int		p[2];
	pid_t	pid;
	int		status;
	char	*content;

	if (pipe(p) == -1)
		return (NULL);
	pid = fork();
	if (pid == -1)
	{
		close(p[0]);
		close(p[1]);
		return (NULL);
	}
	if (pid == 0)
		ex_child(p[1], delimiter, quoted, shell);
	close(p[1]);
	content = read_all_fd(p[0]);
	close(p[0]);
	waitpid(pid, &status, 0);
	return (handle_heredoc_status(status, content, shell));
}
