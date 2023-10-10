
Fonction					Utilité												Bibliothèque
--------------------------------------------------------------------------------------------------
open						Ouvrir un fichier									unistd.h, fcntl.h
close						Fermer un descripteur de fichier					unistd.h
read						Lire depuis un descripteur de fichier				unistd.h
write						Écrire vers un descripteur de fichier				unistd.h
printf						Afficher du texte formaté							stdio.h
malloc						Allouer de la mémoire dynamiquement					stdlib.h
free						Libérer la mémoire allouée							stdlib.h
perror						Imprimer un message d'erreur						stdio.h
strerror					Obtenir une chaîne de message d'erreur				string.h
exit						Terminer l'exécution du programme					stdlib.h
sin, cos, etc.				Fonctions mathématiques								math.h (-lm)
mlx_init					Initialiser la connexion à la fenêtre graphique		mlx.h (MinilibX)
mlx_new_window				Créer une nouvelle fenêtre							mlx.h (MinilibX)
mlx_pixel_put				Dessiner un pixel dans une fenêtre					mlx.h (MinilibX)
mlx_new_image				Créer une nouvelle image							mlx.h (MinilibX)
mlx_put_image_to_window		Afficher une image dans une fenêtre					mlx.h (MinilibX)