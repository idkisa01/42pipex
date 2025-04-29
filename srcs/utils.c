/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:13:29 by isabegar          #+#    #+#             */
/*   Updated: 2025/04/22 13:13:00 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

static void create_child1(int infile, int pipe_fd[2], char **argv, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork 1");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
	{
		close(pipe_fd[0]);
		execute_cmd1(infile, pipe_fd, argv[2], argv[3]);
	}
}

static void create_child2(int outfile, int pipe_fd[2], char **argv, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork 2");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
	{
		close(pipe_fd[1]);
		execute_cmd2(outfile, pipe_fd, argv[4]);
	}
}

void execute_cmd1(int infile, int pipe_fd[2], char *cmd1, char *pattern)
{
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	
	printf("Ejecutando cmd1: %s %s\n", cmd1, pattern);
	execlp(cmd1, cmd1, pattern, NULL);
	perror("exec cmd1");
	exit(EXIT_FAILURE);
}

void execute_cmd2(int outfile, int pipe_fd[2], char *cmd2)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	
	printf("Ejecutando cmd2: %s\n", cmd2);
	execlp(cmd2, cmd2, NULL);
	perror("exec cmd2");
	exit(EXIT_FAILURE);
}


void call_forks(int infile, int outfile, int pipe_fd[2], char **argv)
{
	pid_t pid1;
	pid_t pid2;

	create_child1(infile, pipe_fd, argv, &pid1);
	create_child2(outfile, pipe_fd, argv, &pid2);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
