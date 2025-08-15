#include "minishell.h"

static char *append_text_part(char *final_str, char *original_str, int start, int end)
{
   char *part;

   part = ft_substr(original_str, start, end - start);
   return (ft_strjoin_and_free(final_str, part));
}

static int process_variable(char **final_str, char *original_str, int i, t_shell *shell)
{
	char *var_name;
	char *var_value;
	int start;

	start = i;
	// CAMBIO: Permitir '?' en nombres de variables
	while (original_str[i] && (ft_isalnum(original_str[i]) || original_str[i] == '_' || original_str[i] == '?'))
		i++;
	var_name = ft_substr(original_str, start, i - start);
	var_value = find_var_value(var_name, shell);
	
	// NUEVO: Manejar el caso especial de $?
	if (ft_strcmp(var_name, "?") == 0)
	{
		// var_value viene de ft_itoa(), ya es una copia que debemos liberar
		*final_str = ft_strjoin_and_free(*final_str, var_value);
	}
	else
	{
		// Variables normales - hacer copia porque var_value apunta a envp
		*final_str = ft_strjoin_and_free(*final_str, ft_strdup(var_value));
	}
	
	free(var_name);
	return (i);
}


/*static int process_variable(char **final_str, char *original_str, int i, t_shell *shell)
{
   char *var_name;
   char *var_value;
   int start;

   start = i;
   while (original_str[i] && (ft_isalnum(original_str[i]) || original_str[i] == '_'))
       i++;
   var_name = ft_substr(original_str, start, i - start);
   var_value = find_var_value(var_name, shell);
   *final_str = ft_strjoin_and_free(*final_str, ft_strdup(var_value));
   free(var_name);
   return (i);
}*/

char *build_expanded_string(char *original_str, t_shell *shell)
{
   char *final_str;
   int i;
   int start;

   final_str = ft_strdup("");
   i = 0;
   start = 0;
   while (original_str[i])
   {
       if (original_str[i] == '$')
       {
           final_str = append_text_part(final_str, original_str, start, i);
           i++;
           i = process_variable(&final_str, original_str, i, shell);
           start = i;
       }
       else
           i++;
   }
   final_str = append_text_part(final_str, original_str, start, i);
   return (final_str);
}

