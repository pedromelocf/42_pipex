/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:32:13 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 19:52:59 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	validate_commands(char **argv, char **envp, t_pipex  *s_pipex)
{
	validar o primeiro comando;
	validar o segundo comando;
	verificar qual o valor deve ser atribuido ao s_pipex->validation;
	alocar memoria com o lenght + 1 dos argvs em s_pipex->pathname[0] e s_pipex->pathname[1];
	armazenar em s_pipex->pathname[0] o caminho executavel do cmd1;
	armazenar em s_pipex->pathname[1] o caminho executavel do cmd2;
	retornar ;
}
