/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:41:42 by joterret          #+#    #+#             */
/*   Updated: 2023/10/23 10:03:05 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_param(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (0);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (0);
	else
		return (1);

}
int	is_map_line(char *line)
{
	int i;
	int hasMapParam = 1;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			hasMapParam = 0;
		}
		
		if (!(line[i] == '0' || line[i] == '1' || line[i] == ' '|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '\n'))
		{
			return (1);
		}
		++i;
	}
	return (hasMapParam);
}

char	*copy_clean_line_map(char *line)
{
	int i;
	int	line_len;
	char	*ret_line;

	i = 0;
	line_len = 0;
	line_len = ft_strlen(line);
	ret_line = malloc((line_len) * sizeof(char));
	while (line[i])
	{
		



		if (line[i] != '\n')
		{	
			ret_line[i] = line[i];
		}
		else if (line[i] == '\n')
		{			
			ret_line[i] = '\0';
			return (ret_line);

		}
		i++;
	}
	//ret_line[i] = 0;
	return (ret_line);
}