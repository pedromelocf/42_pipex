/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:32:13 by pmelo-ca          #+#    #+#             */
/*   Updated: 2024/01/16 20:37:57 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	validate_commands(char **argv, char **envp, t_pipex  *s_pipex)
{
	char **path;
	char **splited;
	int		i;

	i = 0;

	if (!ft_strchr(argv[1], '/')) // valida se o argv[1] contem '/', pois indica que é um diretorio.
	{
		validar se o pathname existe;
		se sim, continua. se não, retorna erro
	}
	if (!ft_strchr(argv[2], '/')) // valida se o argv[2] contem '/', pois indica que é um diretorio.
	{
		validar se o pathname existe;
		se sim, continua. se não, retorna erro
	}
	while (envp[i] for diferente de PATH=)
	{
		continua ate a ultima posição de envp até encontrar.
		se encontrar alocar memoria com o lenght + 1 e define o path[0] os possiveis caminhos , se não encontrar, retorna erro.
	}
	while (!(splited = ft_split(path[0], ':' ))) // separa o possivel path em diretorios
	{
		if(acess(splited, X_OK) == 0) // diretorio encontrado
	}

	verificar qual o valor deve ser atribuido ao s_pipex->validation;
	alocar memoria com o lenght + 1 dos argvs em s_pipex->pathname[1] e s_pipex->pathname[2];
	armazenar em s_pipex->pathname[0] o caminho executavel do cmd1;
	armazenar em s_pipex->pathname[1] o caminho executavel do cmd2;
	retornar ;
}
