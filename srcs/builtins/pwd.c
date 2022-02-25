#include "pwd.h"

void	ft_pwd(void)
{
	char	*line;

	line = NULL;
	line = getcwd(line, 2048);
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	return ;
}
