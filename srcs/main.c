/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/18 18:27:43 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int main(int argc, char **argv)
{
	
	t_cub cub3d;
	
	if (argc < 2)
		return (1);

	
	//SECTION - Parsing
	//check_map_file(argv[1]);
	build_map_tab(&cub3d, argv[1]);
	//fill_map_struct(&cub3d);

	//SECTION - temp test zone
	//print_struct_data(&cub3d);


	return (0);
}

// il faut ouvire le fichier map avec open 
// il faut lire le fichier avec get next line pour remplire un tableau
// reprendre ce tableau est remplire les elements de la structe avec
// faire des test d impressions des elements de la structe pour verifier qu ils corespondent a ce quon attend
