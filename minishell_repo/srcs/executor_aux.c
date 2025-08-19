#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}		
	return (s1[i] - s2[i]);
}

char	**ultra_split(t_token *token_list)
{
	int		i;
	char	**argv;
	int		word;
	t_token	*current;

	current = token_list;
	word = 0;
	i = 0;
	argv = NULL;
	while (current)		
	{
		word++;
		current = current->next;
	}
	current = token_list;
	argv = malloc(sizeof(char *) * (word + 1));
	while (current)
	{
		argv[i] = ft_strdup(current->str);
		current = current->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	execute_builtin(t_cmd *cmd, t_shell *shell)
{
	int	saved_stdin;

	saved_stdin = -1;
	if (setup_heredoc_stdin(cmd, &saved_stdin) != 0)
	{
		restore_stdin_from_saved(&saved_stdin);
		return ;
	}
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		ft_echo(cmd, shell);
/*  else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
        funcion_pwd(cmd, shell);
    else if (ft_strcmp(cmd->argv[0], "cd") == 0)
        funcion_cd(cmd, shell);
    else if (ft_strcmp(cmd->argv[0], "unset") == 0)
        funcion_unset(cmd, shell);
    else if (ft_strcmp(cmd->argv[0], "export") == 0)
        funcion_export(cmd, shell);
    else if (ft_strcmp(cmd->argv[0], "env") == 0)
        funcion_env(cmd, shell);
    else if (ft_strcmp(cmd->argv[0], "exit") == 0)
        funcion_exit(cmd, shell);*/
	restore_stdin_from_saved(&saved_stdin);
}

static int	create_and_wait_child(char *cmd_path, t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (-1);
	}
	if (pid == 0)
	{
		if (setup_heredoc_stdin(cmd, NULL) != 0)
			exit(1);
		execve(cmd_path, cmd->argv, shell->envp);
		exit(127);
	}
	free(cmd_path);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->last_status = 128 + WTERMSIG(status);
	return (0);
}

void	run_external(t_cmd *cmd, t_shell *shell)
{
	char	*cmd_path;

	cmd_path = resolve_command_path(cmd->argv[0], shell);
	if (!cmd_path)
	{
		write(STDERR_FILENO, cmd->argv[0], ft_strlen(cmd->argv[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		shell->last_status = UNKNOWN_COMMAND;
		return ;
	}
	create_and_wait_child(cmd_path, cmd, shell);
}
