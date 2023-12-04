/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advent.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:54:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/03 23:32:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVENT_H
# define ADVENT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../libft/gnl.h"
# include "error.h"
# include "colors.h"

# ifndef MAXCOM
#  define MAXCOM 1000 // max number of letters to be supported
# endif
# ifndef MAXLIST
#  define MAXLIST 100 // max number of commands to be supported
# endif

// Clearing the shell using escape sequences

#endif