/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:48:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/04 01:17:15 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/advent.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

int	RED_CUBES = 12;
int	GREEN_CUBES = 13;
int	BLUE_CUBES = 14;

int	find_color(const char *hand_color)
{
	char *numw[4] = {"red", "green", "blue", NULL};
	int i = 0;
	int valid = 0;
	
	if (ft_strlen(hand_color) < 3)
		return (-1);
	//valid = 1;
	hand_color = ft_strtrim_free((char *)hand_color, "\n");
	hand_color = ft_strtrim_free((char *)hand_color, " ");
	
	// printf("%shand_color = %s%s\n",SCYN, hand_color, SWHT);


	while (numw[i])
	{
		// printf("=1>detecting  color  : hand_color = (%s), testing color :(%s)\n", hand_color, numw[i]);
		if (ft_strlen(hand_color) >= ft_strlen(numw[i]))
		{
			// printf("len(hand_color) = %d, len(color) = %d\n", (int)ft_strlen(hand_color), (int)ft_strlen(numw[i]));
			// printf("=2>detecting  color  : hand_color = (%s), testing color :(%s)\n", hand_color, numw[i]);
			if(ft_strnstr(hand_color, numw[i], ft_strlen(numw[i])) != NULL)
			{
				valid = ft_atoi(hand_color);
				// printf("%sSOLUTION = %d %s%s\n", SCYN, valid, numw[i], SWHT);
				break ;
			}
		}
		i++;
	}
	// printf("%sSOLUTION = %d %s%s\n", SCYN, valid, numw[i], SWHT);
	if (valid > i + 12)
	{
		// printf("%sIMPOSSIBLE%s\n",SRED,SWHT);
		return (0);
	}
	// printf("%sOK%s\n", SGRN, SWHT);
	return (1);
}
/*
int find_color(char *hand_color)
{
	int i, j;

	

}*/

void	advent(char *file)
{
	char	*line;
	int		i, j;
	int		fd;
	int 	sum = 0;
	int     valid;
	int		valid_games = 1;
	// int		line_num;
	char	**hand;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	
	if (line == NULL)
		return ;
	while (line)
	{
		i = 0;
		printf("%sGAME NUM : %d%s\n", SCYN, valid_games, SWHT);
		printf("line = %s", line);
		while (line[i] != ':' && line[i])
			i++;
		if (line[i] == '\0')
			return ;
		hand = ft_split(line + i + 1, ';');
		i = 0;
		valid = 1;
		while (hand[i])
		{
			j = 0;
			hand[i] = ft_strtrim_free(hand[i], "\n");
			// printf("******* hand_color[%d] = %s \n", i, hand[i]);
			char **hand_color = ft_split(hand[i], ',');
			while(hand_color[j])
			{
				// printf("%shand_color[%d] = %s%s : ",SYLW, j, hand_color[j], SWHT);
				if (!find_color(hand_color[j]))
				{
					valid = 0;
					break ;
				}
				j++;
			}
			// printf("MAIN valid = %d\n", valid);
			//valid *= (!find_color(hand_color[i]));
			if(!valid)
				break ;
			i++;
		}
		if (valid)
		{
			sum += valid_games;// * valid;
			printf("%sVALID GAME : %d, SUM : %d %s\n", SGRN, valid_games, sum, SWHT);
		}
		valid_games ++;
		line = get_next_line(fd);
	}
	printf("%sSOLUTION = %d%s\n", SGRN, sum, SWHT);
	close(fd);
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{


	
	(void)envp;
	if (argc == 2)
		advent(argv[1]);
	else
		ft_putstr_fd("Error\n", 2);	
	return (0);
}