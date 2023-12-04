/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-1-2-trebuchet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:48:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/03 23:50:32 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/advent.h"

int	ft_strfinddigit(const char *line)
{
	char *numw[11] = {"zero", "one", "two", "three", "four", "five", 
		"six", "seven", "eight", "nine", NULL};
	int i = 0;

	if (ft_strlen(line) < 3)
		return (-1);
	
	while (numw[i])
	{
		if (ft_strlen(line) >= ft_strlen(numw[i]) && !ft_strncmp(line, numw[i], ft_strlen(numw[i])))
			return (i);
		i++;
	}
	return (-1);
}

int ft_strcharnum(char *line)
{
	int i;
	int j;
	int c;
	char digit[3];


	i = 0;
	c = -1;
	digit[1] = '\0';
	digit[2] = '\0';
	
	while (line[i])
	{
		if (ft_isdigit(line[i]) || ft_strfinddigit(line + i) >= 0)
		{
			if (ft_isdigit(line[i])) 
				digit[0] = line[i];
			else if (ft_strfinddigit(line + i) >= 0)
				digit[0] = ft_strfinddigit(line + i) + '0';
			break ;
		}
		i++;
	}
	if (i == (int)ft_strlen(line))
		return (0);
	j = ft_strlen(line) - 1;
	while (j >= i)
	{
		if (ft_isdigit(line[j]) || ft_strfinddigit(line + j) >= 0)
		{
			if (ft_isdigit(line[j]))
				digit[1] = line[j];
			else if (ft_strfinddigit(line + j) >= 0)
				digit[1] = ft_strfinddigit(line + j) + '0';
			break ;
		}
		j--;
	}
	c = ft_atoi(digit);
	return (c);
}

int main(int argc, char *argv[], char *envp[])
{
	char *line;
	int code = 0;
	int code_i = 0;
	int fd;
	int line_num = 1;

	
	(void)envp;
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);	
		return (0);
	}
	fd = open(argv[1], O_RDONLY);	
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	
	while (line)
	{
		code_i = ft_strcharnum(line);
		code += code_i;
		printf("soma = %d => line %d = %d : %s",code,  line_num++, code_i, line);
		line = get_next_line(fd);
	}
	printf("%d\n", code);
	return (0);
}