#include "cd.h"

void	ft_cd(char *path_name, char **dupenv)
{
	char	*dir;
	char	*new_wd;
	int		i;
	int		len_cwd;

	i = 0;
	chdir(path_name);
	dir = NULL;
	dir = getcwd(dir, 2048);
	len_cwd = ft_strlen(dir);
	new_wd = malloc(sizeof(char) * (len_cwd + 5));
	if (!new_wd)
		return ;
	new_wd = "PWD=";
	while (dupenv[i] && ft_strncmp(dupenv[i], "PWD=", 4) != 0)
	{
		printf("val i = %d\n", i);
		i++;
	}

	new_wd = ft_strjoin(new_wd, dir);
	dupenv[i] = new_wd;
}