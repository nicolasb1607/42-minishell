#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void) envp;
	t_minishell mshell;
	t_tlist *tlist;

	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;

	char	*str = " \" $teub \" "; // <- fais le truc bizarre
	// char	*str = "Salut qq6ch \"$USER \" 780 derriere yolo test test prout"; // <- quand on ajoute un espace apres ca segfault pas mais ne vas pas chercher nicolas
	// char	*str = "Salut qq6ch \"$USER                                    \" 780 derriere yolo test test prout"; // etrange
	// char	*str = "Salut qq6ch \" $USER \" 780 derriere yolo test test prout"; // <- marche mais garde les espace ( avant et apres )
	//char	*str = "$USER"; // Marche c cool
	// char	*str = "\"$PWD $USER $SHELL\""; // ne vas jamais marcher si il ny a pas despace apres la variable
	// char	*str = "\"$PWD test $USER test $SHELL\"";	 // mais va marcher si ce n'est pas une variable
	// char	*str = "\"$SHELL\""; // aussi marche pas si ya rien avant la premiere variable
	// char	*str = "\"           $USER                          \"";
	/*  */


	tlist = init_tlist(str, tlist, &mshell);

	ft_printtoklst(tlist);

	return (0);
}
