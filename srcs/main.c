/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/12 18:42:05 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int main(int argc, char **argv)
{
	char *cubtest;
	if (argc < 2)
		return (1);
	cubtest = argv[1];
	printf("LA MAP\n %s\n", cubtest);
	return (0);
}

// il faut ouvire le fichier map avec open 
// il faut lire le fichier avec get next line pour remplire un tableau
// reprendre ce tableau est remplire les elements de la structe avec
// faire des test d impressions des elements de la structe pour verifier qu ils corespondent a ce quon attend
