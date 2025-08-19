#include "minishell.h"

void	restore_stdin_from_saved(int *saved_stdin);
void	run_external(t_cmd *cmd, t_shell *shell);
int		is_builtin(char *cmd);


void restore_stdin_from_saved(int *saved_stdin)
{
	if (saved_stdin && *saved_stdin != -1)
	{
		dup2(*saved_stdin, STDIN_FILENO);
		close(*saved_stdin);
		*saved_stdin = -1;
	}
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
	int saved_stdin; 
	int saved_stdout;

	saved_stdout = -1;
	saved_stdin = -1;
	if (!commands || !commands->argv || !commands->argv[0])
		return ;
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
	if (is_builtin(commands->argv[0]))
		execute_builtin(commands, shell);
	else
		run_external(commands, shell);
	restore_redirections(&saved_stdin, &saved_stdout);
}
