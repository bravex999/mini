#include "minishell.h"
static int  get_len_double_join(char *line, int *i);

char *words_join(char *line, int *i, t_shell *shell)
{
    (void)shell;
    int start_word;
    char *line_token;
    int len;
  /*char *expand_line;*/
     len = 0;
     start_word = *i;
     while(line[*i] && line[*i] != ' ' && line[*i] != '"' && line[*i] != '\'' &&
                   line[*i] != '|' && line[*i] != '>' && line[*i] != '<')
     {
         len++;
         (*i)++;
     }
     line_token = ft_substr(line, start_word, len);
     if(!line_token)
         return (NULL);
    /* if(ft_strchr(line_token, '$'))
     {
         expand_line = expander(line_token, shell);
         free(line_token);
         return(expand_split(expand_line));
     }*/
     return(line_token);
}

char *handle_quotes_join(char *line, int *i, t_shell *shell)
{
    (void)shell;
    char *line_token;

	if (line[*i] == '"')
      line_token = handle_double_join(line, i, shell);
    else
        line_token = handle_single_join(line, i);
    return(line_token);
}

char *handle_double_join(char *line, int *i, t_shell *shell)
{   
     (void)shell;
	 int len;
     int start_word;
     char *line_token;
/*	 char *expand_line;*/
     
     start_word = ++(*i);
	 len = get_len_double_join(line, i);
     if(line[*i] == '"')
     {
         (*i)++;
         line_token = ft_substr(line, start_word, len);
		 if(!line_token)
              return (NULL);
		/* if(ft_strchr(line_token, '$'))
		 {
			 expand_line = expander(line_token, shell);
			 free(line_token);
			 return(expand_split(expand_line));
		 }*/
		 return (line_token);
	 }	 
     write(STDERR_FILENO, "minishell: syntax error: unclosed quote\n", 41);
     return (NULL);
 }

char *handle_single_join(char *line, int *i)
{
      int len;
      int start_word;
      char *line_token;
 
      len = 0;
      start_word = ++(*i);
      while(line[*i] && line[*i] != '\'')
      {
          len++;
          (*i)++;
      }
      if(line[*i] == '\'')
      {
          (*i)++;
          line_token = ft_substr(line, start_word, len);
          if(!line_token)
              return (NULL);
          return (line_token);
      }
      write(STDERR_FILENO, "minishell: syntax error: unclosed quote\n", 41);
      return (NULL);
  }

static int	get_len_double_join(char *line, int *i)
{
	int	len;

	len = 0;
	while (line[*i] && line[*i] != '"')
	{
		len++;
		(*i)++;
	}
	return (len);
}
