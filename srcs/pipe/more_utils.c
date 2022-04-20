/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:07:20 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/20 11:10:31 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

t_data	get_args(int argc, char **argv, char **envp)
{
	t_data	tmp;

	tmp.argc = argc;
	tmp.argv = argv;
	tmp.envp = envp;
	tmp.infile = 0;
	tmp.outfile = 0;
	return (tmp);
}

