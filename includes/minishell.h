/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:35 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/15 12:18:19 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/history.h>
# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>

# include "libft.h"
# include "structs.h"
# include "prompt.h"
# include "pwd.h"
# include "env.h"
# include "cd.h"
# include "unset.h"
# include "export.h"
# include "pipe.h"
# include "lexer.h"
# include "utils.h"
# include "init_ft.h"
# include "free.h"
# include "echo.h"
# include "exec.h"
# include "colors.h"
# include "handle_sig.h"
# include "mpipe.h"
// # include "exit.h"

extern t_minishell g_mshell;

#endif