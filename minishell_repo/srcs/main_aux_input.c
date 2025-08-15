#include "minishell.h"

char	*read_input(void)
{
	return (readline("minishell$ "));
}

int	check_ctrl_d(char *line)
{
	if (!line)
	{
		printf("exit\n");
		rl_clear_history();
		return (1);
	}
	return (0);
}

int	handle_ctrl_c_signal(char **line)
{
	printf("Checking g_signal: %d\n", g_signal);  // <- TEMPORAL
	if (g_signal == SIGINT)
	{
		printf("Calling handle_ctrl_c\n");  // <- TEMPORAL
		return (handle_ctrl_c(line));
	}	
	return (0);
}

int	history(char *line)
{
	if (!line)
		return (0);
	while (*line == ' ' || *line == '\t')
		line++;
	return (*line != '\0');
}
