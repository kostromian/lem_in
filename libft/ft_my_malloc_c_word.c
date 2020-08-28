/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_malloc_c_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <icanker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:59:58 by icanker           #+#    #+#             */
/*   Updated: 2020/08/28 12:59:58 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_malloc_c_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (void*)0;
	if (s)
	{
		while (s[i] && s[i] != c)
			i++;
		word = (char*)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (s[i] && s[i] != c)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}