/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:40 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/24 11:38:49 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../lib/printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid_child1;
	pid_t	pid_child2;
	char	**argv;
	char	**env;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	int		status;
}			t_pipex;

t_pipex		*init_pipex(char **argv, char **env);
void		child_process1(t_pipex *s_pipex);
void		child_process2(t_pipex *s_pipex);
void		execute(t_pipex *s_pipex, char *argv);
char		*get_path(t_pipex *s_pipex, char *cmd);

#endif
