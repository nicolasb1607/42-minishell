#include "cd.h"

#define NO_ACCESS "no such file or directory\n"

static void	maj_old_pwd(char **dupenv, char *curr_dir)
{
	int		i;
	char	*old_dir;

	if(is_existing("OLDPWD", dupenv) == 0)
		return ;
	old_dir = malloc(sizeof(char) * 8);
	if (!old_dir)
		return ;
	old_dir = "OLDPWD=";
	i = 0;
	while (dupenv[i] && ft_strncmp(dupenv[i], "OLDPWD=", 7) != 0)
		i++;
	old_dir = ft_strjoin(old_dir, curr_dir);
	dupenv[i] = old_dir;
	free(curr_dir);
}

void	ft_cd(char *path_name, char **dupenv)
{
	char	*curr_dir;
	char	*new_wd;
	int		i;

	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 2048);
	if(!curr_dir)
		return ;
	maj_old_pwd(dupenv, curr_dir);
	if (chdir(path_name) == -1)
	{
		ft_putstr(NO_ACCESS);
		return ;
	}
	if(is_existing("PWD", dupenv) == 0)
		return ;
	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 2048);
	if(!curr_dir)
		return ;
	new_wd = malloc(sizeof(char) * 5);
	if (!new_wd)
		return ;
	new_wd = "PWD=";
	i = 0;
	while (dupenv[i] && ft_strncmp(dupenv[i], "PWD=", 4) != 0)
		i++;
	new_wd = ft_strjoin(new_wd, curr_dir);
	dupenv[i] = new_wd;
	free(curr_dir);
}
