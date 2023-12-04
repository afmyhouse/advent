/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:27:02 by antoda-s          #+#    #+#             */
/*   Updated: 2023/12/04 00:10:17 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 			Locates the first occurrence of the null-terminated string
/// @param big		String where to search occurences of `little` string
/// @param little	Substring to search for
/// @param len		Number of bytes to search
/// @return			Pointer to the located character, or NULL if not found
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*phs;
	size_t	lns;

	lns = ft_strlen(big);
	//printf("color = %s, lns = %zu\n", little, lns);
	phs = (char *)big;
	if (!*little)
		return (phs);
	if (len == 0 || !*phs)
		return (NULL);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	//printf("phs = %s, len = %zu\n", phs, len);
	//printf("while0 phs - big + lns = %zu\n", (size_t)(phs - big + lns));
	while (*phs && (size_t)(phs - big + lns) >= len)
	{
		//printf("while1 phs - big + lns = %zu\n", (size_t)(phs - big + lns));
		//printf("while1 phs = %s,\n", phs);
		if (!ft_strncmp(phs, little, lns))
			return (phs);
		phs++;
		//printf("while2 phs - big + lns = %zu\n", (size_t)(phs - big + lns));
		//printf("while2 phs = %s,\n", phs);
		
	}
	// printf("exit here! NULL\n");
	return (NULL);
}
