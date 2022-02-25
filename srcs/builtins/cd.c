#include "cd.h"

#define NO_ACCESS "no such file or directory\n"

static void	maj_old_pwd(t_dlist **dupenv, char *curr_dir)
{
	char	*content;
	t_dlist	*curr;

	curr = *dupenv;
	content = curr->content;
	if (is_existing("OLDPWD", dupenv) == 0)
		return ;
	while (curr && ft_strncmp(content, "OLDPWD=", 7) != 0)
	{
		curr = curr->next;
		content = curr->content;
	}
	content = ft_strjoin("OLDPWD=", curr_dir);
	free(curr->content);
	curr->content = content;
}

void	ft_cd(char *path_name, t_dlist **dupenv)
{
	char	*curr_dir;
	char	*content;
	t_dlist	*curr;

	curr = *dupenv;
	content = curr->content;
	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 2048);
	if (!curr_dir)
		return ;
	maj_old_pwd(dupenv, curr_dir);
	if (chdir(path_name) == -1)
	{
		ft_putstr(NO_ACCESS);
		return ;
	}
	if (is_existing("PWD", dupenv) == 0)
		return ;
	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 2048);
	if (!curr_dir)
		return ;
	while (curr && ft_strncmp(content, "PWD=", 4) != 0)
	{
		curr = curr->next;
		content = curr->content;
	}
	content = ft_strjoin("PWD=", curr_dir);
	free(curr->content);
	curr->content = content;
}	
