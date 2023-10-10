# so_long
Vous devez utiliser la MiniLibX. Soit la version disponible sur les machines de
l’école, soit en l’installant par les sources.

- ✅ Vous devez rendre un Makefile qui compilera vos fichiers sources. Il ne doit pas relink.
- ✅ Votre programme doit prendre en paramètre un fichier de carte se terminant par l’extension .ber.

## Le jeu
- ✅ Le but du joueur est de collecter tous les items présents sur la carte, puis de s’échapper en empruntant le chemin le plus court possible.
- ✅ Les touches W, A, S et D doivent être utilisées afin de mouvoir le personnage principal.
- ✅ Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas, gauche, droite.
- ✅ Le joueur ne doit pas pouvoir se déplacer dans les murs.
- ✅ À chaque mouvement, le compte total de mouvement doit être affiché dans le shell.
- ✅ Vous devez utiliser une vue 2D (vue de haut ou de profil).
- ✅ Le jeu n’a pas à être en temps réel.
- ✅ Bien que les exemples donnés montrent un thème dauphin, vous êtes libre de créer l’univers que vous voulez.

## Gestion graphique
- ✅ Votre programme doit afficher une image dans une fenêtre.
- ✅ La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).
- ✅ Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme proprement.
- ✅ Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme proprement.
- ✅ Utiliser les images de la MiniLibX est obligatoire.

## La carte
- ✅ La carte sera construite en utilisant 3 éléments : les murs, les items à collecter,
	et l’espace vide.
- ✅ Votre carte peut être composée de ces 5 caractères :
	- 0 pour un emplacement vide,
	- 1 pour un mur,
	- C pour un item à collecter (C pour collectible),
	- E pour une sortie (E pour exit),
	- P pour la position de départ du personnage.
- ✅ La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.
- ✅ Si la map contient des doublons, vous devez afficher un message d’erreur.
- ✅ La carte doit être de forme rectangulaire.
- ✅ La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le programme retourne une erreur.
- ✅ Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter) dans la carte.
- ✅ Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles énoncées ci-dessus.
- ✅ Si une erreur de configuration est détectée, le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
