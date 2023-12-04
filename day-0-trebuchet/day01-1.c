/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day01-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:48:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/04 02:12:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/advent.h"

int ft_strcharnum(char *line)
{
	int in;
	int iw;
	int jn;
	int jw;
	int c;
	char digit[3];


	in = 0;
	c = 0;
	digit[1] = '\0';
	digit[2] = '\0';
	
	while (line[in])
	{
		if (ft_isdigit(line[in]))
			break;
		in++;
	}
	if (!ft_isdigit(line[in]))
		return (0);
	jn = ft_strlen(line) - 1;
	while (jn >= in)
	{
		if (ft_isdigit(line[jn]))
			break;
		jn--;
	}
	digit[0] = line[in];
	digit[1] = line[jn];	
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