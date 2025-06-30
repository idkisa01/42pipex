/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:42:57 by isabegar          #+#    #+#             */
/*   Updated: 2025/06/26 13:42:57 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_child1(int infile, int pipe_fd[2], char *cmd, char **envp)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		exit (1);
	}	
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		exit (1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(cmd, envp);
}

static void	create_child2(int outfile, int pipe_fd[2], char *cmd, char **envp)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		exit (1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		exit (1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(cmd, envp);
}

void	call_forks(int infile, int outfile, int pipe_fd[2], char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork1");
		exit (1);
	}
	if (pid1 == 0)
		create_child1(infile, pipe_fd, argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork2");
		exit (1);
	}
	if (pid2 == 0)
		create_child2(outfile, pipe_fd, argv[3], envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
