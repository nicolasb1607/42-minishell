/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:35 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/25 13:42:59 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/history.h>
# include <stdio.h>
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

#endif