#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_vars	
{
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
	char	**path;

}t_vars;

int	parsing(t_vars *vars, char **av, char **envp);

#endif