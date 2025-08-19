#include "minishell.h"

static char	*app_tx(char *final_str, char *original_str, int start, int end)
{
	char	*part;

	part = ft_substr(original_str, start, end - start);
	return (ft_strjoin_and_free(final_str, part));
}

static int	pro_var(char **final_str, char *original_str, int i, t_shell *shell)
{
	char	*var_name;
	char	*var_value;
	int		start;

	start = i;
	while (original_str[i] && (ft_isalnum(original_str[i])
			|| original_str[i] == '_' || original_str[i] == '?'))
		i++;
	var_name = ft_substr(original_str, start, i - start);
	var_value = find_var_value(var_name, shell);
	if (ft_strcmp(var_name, "?") == 0)
		*final_str = ft_strjoin_and_free(*final_str, var_value);
	else
		*final_str = ft_strjoin_and_free(*final_str, ft_strdup(var_value));
	free(var_name);
	return (i);
}

char	*build_expanded_string(char *original_str, t_shell *shell)
{
	char	*final_str;
	int		i;
	int		start;

	final_str = ft_strdup("");
	i = 0;
	start = 0;
	while (original_str[i])
	{
		if (original_str[i] == '$')
		{
			final_str = app_tx(final_str, original_str, start, i);
			i++;
			i = pro_var(&final_str, original_str, i, shell);
			start = i;
		}
		else
			i++;
	}
	final_str = app_tx(final_str, original_str, start, i);
	return (final_str);
}
