#include "minishell.h"
/*#include "builtins.h"
#include "../includes/shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>*/

static int check_valid_nflag(char *arg)
{
    int i;

    if (!arg || arg[0] != '-' || arg[1] != 'n')
        return 0;
    i = 2;
    while (arg[i] && arg[i] == 'n')
        i++;
    if (arg[i] == '\0')
        return 1;
    return 0;
}

int ft_echo(t_cmd *cmd, t_shell *shell)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    while (cmd->argv[i] && check_valid_nflag(cmd->argv[i]))
    {
        newline = 0;
        i++;
    }
    while (cmd->argv[i])
    {
		ft_putstr_fd(cmd->argv[i], 1);
        if (cmd->argv[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (newline)
        write(1, "\n", 1);
    shell->last_status = EXIT_OK;
    return 0;
}
