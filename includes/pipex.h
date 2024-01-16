/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:40 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 19:28:45 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../../lib/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid;
	char	**pathname;
	int		pipe_fd[2];
	int		argc;
	int		infile;
	int		outfile;
	int		validation;
}			t_pipex;

t_pipex init_pipex(char **argv, char **envp);

#endif
