/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:04:39 by isabegar          #+#    #+#             */
/*   Updated: 2025/07/01 11:01:36 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	char	**argv;
	char	**envp;
}	t_pipex;

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);

void	call_forks(t_pipex *px);
void	execute_cmd(char *cmd_str, char **envp);
#endif
