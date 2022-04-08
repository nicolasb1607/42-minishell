/*
!	TODO :
!		Pipes :
*		- Faire en sorte que quand on a des options apres une redirection, elles soient prisent en compte
*		- Créer les fichiers (En O_APPEND si drdir, en O_TRUNC si simple rdir)
!		Transformer le pipex pour quil prenne t_cmd au lieu de argc argv
!		- A chaque fois qu'on va executer une fonction, on va regarder si on doit changer de dup pour le infile / outfile
!		|_ Faire une fonction update_io_pipe (pourrait etre appelée a chaque execution de commandes)

?	NOTES :
?	Quand on a une redirection puis un pipe on va reset le fd de sortie des commandes
*/