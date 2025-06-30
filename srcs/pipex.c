/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:04:57 by isabegar          #+#    #+#             */
/*   Updated: 2025/06/26 21:02:53 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Use:./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		return (1);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (perror("infile error"), 1);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (perror("outfile error"), close(infile), 1);
	if (pipe(pipe_fd) == -1)
		return (perror("pipe error"), close(infile), close(outfile), 1);
	call_forks(infile, outfile, pipe_fd, argv, envp);
	close(infile);
	close(outfile);
	return (0);
}
