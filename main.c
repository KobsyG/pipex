#include "pipex.h"



int	main(int ac, char **av, char **envp)
{
	t_vars	vars;
	int		pfd[2];
	int		pid;

	parsing(&vars, av, envp);
	pipe(pfd);
	pid = fork();
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		execve(vars.cmd2, 0, vars.path);
		return (3);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execve(vars.cmd1, &av[1], vars.path);
		return (3);
	}
	return (4);
}
