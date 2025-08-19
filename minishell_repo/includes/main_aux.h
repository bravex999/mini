#ifndef MAIN_AUX_H
# define MAIN_AUX_H

void	start_loop(t_shell *shell);
int		handle_ctrl_c(char **line);
int		check_ctrl_d(char *line); // Gestión ctrl D
char	*read_input(void);
int		handle_ctrl_c_signal(char **line);
int		history(char *line);

#endif
