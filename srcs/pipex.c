/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:04:57 by isabegar          #+#    #+#             */
/*   Updated: 2025/07/01 10:57:17 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_pipe_error(t_pipex *px)
{
	perror("pipe error");
	close(px->infile);
	close(px->outfile);
	free(px);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*px;

	if (argc != 5)
	{
		ft_putendl_fd("Use:./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		return (1);
	}
	px = malloc(sizeof(t_pipex));
	if (!px)
		return (perror("malloc error"), 1);
	px->argv = argv;
	px->envp = envp;
	px->infile = open(argv[1], O_RDONLY);
	if (px->infile == -1)
		return (perror("infile error"), free(px), 1);
	px->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile == -1)
		return (perror("outfile error"), close(px->infile), free(px), 1);
	if (pipe(px->pipe_fd) == -1)
		return (handle_pipe_error(px));
	call_forks(px);
	close(px->infile);
	close(px->outfile);
	free(px);
	return (0);
}
