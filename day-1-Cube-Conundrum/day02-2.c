/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:48:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/04 02:04:27 by antoda-s         ###   ########.fr       */
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

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);

}

int	find_color(char **hand_color, int num[])
{
	char	*numw[4] = {"red", "green", "blue", NULL};
	// int		num[3];
	
	int i = 0;
	int j = 0;
	int valid = 0;
	
	valid = 1;
	while(hand_color[j])
	{
		
		hand_color[j] = ft_strtrim_free((char *)hand_color[j], "\n");
		hand_color[j] = ft_strtrim_free((char *)hand_color[j], " ");
		i = 0;
		while (numw[i])
		{
			// printf("=1>detecting  color  : hand_color = (%s), testing color :(%s)\n", hand_color, numw[i]);
			if (ft_strlen(hand_color[j]) >= ft_strlen(numw[i]))
			{
				// printf("len(hand_color) = %d, len(color) = %d\n", (int)ft_strlen(hand_color), (int)ft_strlen(numw[i]));
				// printf("=2>detecting  color  : hand_color = (%s), testing color :(%s)\n", hand_color, numw[i]);
				if(ft_strnstr(hand_color[j], numw[i], ft_strlen(numw[i])) != NULL)
				{
					num[i] = ft_max(ft_atoi(hand_color[j]), num[i]);
					printf("num[%d] = %d\n", i, num[i]);
				}
			}
			i++;
		}
		j++;
	}
	// printf("%sSOLUTION = %d %s%s\n", SCYN, valid, numw[i], SWHT);
	valid *= num[0] * num[1] * num[2];
	// printf("%sOK%s\n", SGRN, SWHT);
	return (valid);
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
	int num[3] = {0, 0, 0};
	
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
			printf("**************\n");
			char **hand_color = ft_split(hand[i], ',');
			find_color(hand_color, num);

			//valid *= (!find_color(hand_color[i]));
			if(!valid)
				break ;
			i++;
		}
		valid = num[0] * num[1] * num[2];
		sum += valid;// * valid;
		printf("%sPOWER GAME : %d, SUM : %d %s\n", SGRN, valid, sum, SWHT);
		num[0] = 0;
		num[1] = 0;
		num[2] = 0;
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