/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:47:56 by isabegar          #+#    #+#             */
/*   Updated: 2025/06/26 13:47:56 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}

static char	**parse_cmd(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("split error");
		exit (1);
	}
	return (args);
}

void	execute_cmd(char *cmd_str, char **envp)
{
	(void)envp;
	char	**args;

	args = parse_cmd(cmd_str);
	execvp(args[0], args);
	perror("execvp");
	ft_free_split(args);
	exit(1);
}
