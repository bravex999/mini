#include "minishell.h"

int	setup_input_redirection(t_cmd *cmd, int *saved_stdin)
{
	int	fd;

	if (!cmd->infile)
		return (0);
	if (*saved_stdin == -1)
	{
		*saved_stdin = dup(STDIN_FILENO);
		if (*saved_stdin == -1)
			return (-1);
	}
	fd = open(cmd->infile, O_RDONLY);
	if (fd == -1)
	{
		perror(cmd->infile);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	open_dup_stdout(const char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	setup_output_redirection(t_cmd *cmd, int *saved_stdout)
{
	int	flags;

	if (!cmd->outfile)
		return (0);
	if (*saved_stdout == -1)
	{
		*saved_stdout = dup(STDOUT_FILENO);
		if (*saved_stdout == -1)
			return (-1);
	}
	if (cmd->append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	return (open_dup_stdout(cmd->outfile, flags));
}

void	restore_redirections(int *saved_stdin, int *saved_stdout)
{
	if (saved_stdin && *saved_stdin != -1)
	{
		dup2(*saved_stdin, STDIN_FILENO);
		close(*saved_stdin);
		*saved_stdin = -1;
	}
	if (saved_stdout && *saved_stdout != -1)
	{
		dup2(*saved_stdout, STDOUT_FILENO);
		close(*saved_stdout);
		*saved_stdout = -1;
	}
}
