/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:04:39 by isabegar          #+#    #+#             */
/*   Updated: 2025/06/28 16:08:53 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
#include <stddef.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
//void	execute_cmd1(int infile, int pipe_fd[2], char *cmd1, char *cmd1_arg);
//void	execute_cmd2(int outfile, int pipe_fd[2], char *cmd2);
void	call_forks(int infile, int outfile, int pipe_fd[2], char **argv, char **envp);
void	execute_cmd(char *cmd_str, char **envp);
#endif
