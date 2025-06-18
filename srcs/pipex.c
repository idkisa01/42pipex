/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:13:17 by isabegar          #+#    #+#             */
/*   Updated: 2025/05/07 11:39:08 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	write(fd, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];
	
	if (argc != 6)
	{
		ft_putendl_fd("Use:./pipex <infile> <cmd1> <patron> <cmd2> <outfile>\n", 2);
		return (EXIT_FAILURE);
	}

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (perror("infile error"), EXIT_FAILURE);

	outfile = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (perror("outfile error"), close(infile), EXIT_FAILURE);

	if (pipe(pipe_fd) == -1)
		return (perror("pipe error"), close(infile), close(outfile), EXIT_FAILURE);

	call_forks(infile, outfile, pipe_fd, argv);
	close(infile);
	close(outfile);
	return (EXIT_SUCCESS);
}
