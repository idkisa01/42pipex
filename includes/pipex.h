/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:13:38 by isabegar          #+#    #+#             */
/*   Updated: 2025/04/21 23:41:25 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	execute_cmd1(int infile, int pipe_fd[2], char *cmd1, char *pattern);
void	execute_cmd2(int outfile, int pipe_fd[2], char *cmd2);
void	call_forks(int infile, int outfile, int pipe_fd[2], char **argv);

#endif
