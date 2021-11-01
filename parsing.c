#include "pipex.h"

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (split[i])
		{
			free(split[i]);
		}
	}
	free(split);
}

static char	**extract_path_env(char **envp)
{
	int		i;
	char	*res;
	char	**split;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0 && envp[i])
		i++;
	res = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	if (!res)
		return (NULL);
	split = ft_split(res, ":");
	free(res);
	i = 0;
	while (split[i])
	{
		split[i] = strjoin_free(split[i], "/", 1);
		if (!split)
		{
			free_split(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}

int	parsing(t_vars *vars, char **av, char **envp)
{
	int	pipefd[2];
	
	vars->fd1 = open(av[1], O_RDONLY);
	vars->fd2 = open(av[4], O_RDWR);
	vars->cmd1 = av[2];
	vars->cmd2 = av[3];
	vars->path = extract_path_env(envp);
}
