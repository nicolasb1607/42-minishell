#include "pwd.h"

char	*ft_pwd(void)
{
	char	*line;

	line = NULL;
	line = getcwd(line, 2048);
	return (line);
}