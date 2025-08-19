#include "minishell.h"

int	is_token_word(t_token *token_list)
{
	if (token_list->type != T_WORD
		&& token_list->type != T_QUOTED_SINGLE
		&& token_list->type != T_QUOTED_DOUBLE)
		return (0);
	return (1);
}
