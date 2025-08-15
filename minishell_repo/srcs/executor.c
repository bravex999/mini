#include "minishell.h"                                                           
                

int  setup_heredoc_stdin(t_cmd *cmd, int *saved_stdin);
void restore_stdin_from_saved(int *saved_stdin);
void run_external(t_cmd *cmd, t_shell *shell);
int  is_builtin(char *cmd);


int setup_heredoc_stdin(t_cmd *cmd, int *saved_stdin)
{
	int     p[2];
	size_t  len, off;
	ssize_t n;

	if (!cmd->heredoc_content)
		return (0);
	if (saved_stdin && *saved_stdin == -1)
	{
		*saved_stdin = dup(STDIN_FILENO);
		if (*saved_stdin == -1)
			return (-1);
	}
	if (pipe(p) == -1)
		return (-1);
	len = ft_strlen(cmd->heredoc_content);
	off = 0;
	while (off < len)
	{
		n = write(p[1], cmd->heredoc_content + off, len - off);
		if (n <= 0)
			break ;
		off += (size_t)n;
	}
	close(p[1]);
	if (dup2(p[0], STDIN_FILENO) == -1)
	{
		close(p[0]);
		return (-1);
	}
	close(p[0]);
	free(cmd->heredoc_content);
	cmd->heredoc_content = NULL;
	if (off < len)
		return (-1);
	return (0);
}

void restore_stdin_from_saved(int *saved_stdin)
{
	if (saved_stdin && *saved_stdin != -1)
	{
		dup2(*saved_stdin, STDIN_FILENO);
		close(*saved_stdin);
		*saved_stdin = -1;
	}
}

void run_external(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	cmd_path = resolve_command_path(cmd->argv[0], shell);
	if (!cmd_path)
	{
		write(STDERR_FILENO, cmd->argv[0], ft_strlen(cmd->argv[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		shell->last_status = UNKNOWN_COMMAND;
		return ;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return ;
	}
	if (pid == 0)
	{
		if (setup_heredoc_stdin(cmd, NULL) != 0)
			_exit(1);
		execve(cmd_path, cmd->argv, shell->envp);
		_exit(127);
	}
	free(cmd_path);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_status = 128 + WTERMSIG(status);
}

int is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
/*	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);*/
	return (0);
}

void execute_commands(t_cmd *commands, t_shell *shell)
{
	int saved_stdin = -1;
	int saved_stdout = -1;

	if (!commands || !commands->argv || !commands->argv[0])
		return ;

	// Setup de redirecciones
	if (setup_heredoc_stdin(commands, &saved_stdin) != 0)
	{
		restore_redirections(&saved_stdin, &saved_stdout);
		return ;
	}
	
	if (setup_input_redirection(commands, &saved_stdin) != 0)
	{
		restore_redirections(&saved_stdin, &saved_stdout);
		return ;
	}
	
	if (setup_output_redirection(commands, &saved_stdout) != 0)
	{
		restore_redirections(&saved_stdin, &saved_stdout);
		return ;
	}

	// Ejecutar comando
	if (is_builtin(commands->argv[0]))
		execute_builtin(commands, shell);
	else
		run_external(commands, shell);

	// Restaurar redirecciones
	restore_redirections(&saved_stdin, &saved_stdout);
}
