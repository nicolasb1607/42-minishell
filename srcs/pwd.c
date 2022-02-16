#include "../includes/pwd.h"

char	*ft_pwd(void)
{
	char	*line;

	line = getenv("PWD");

	printf("Return : %s\n", line);
	return (line);
}