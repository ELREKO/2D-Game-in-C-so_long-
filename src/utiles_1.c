/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:38:27 by rkost             #+#    #+#             */
/*   Updated: 2023/11/10 16:42:47 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_putchar(char ch)
{
	ssize_t	ret;

	ret = write(1, &ch, 1);
	if (ret == -1)
		perror("ERROR : write!");
}

void	ft_putstr(char *str)
{
	int	i_count;

	i_count = 0;
	while (str[i_count] != '\0')
	{
		ft_putchar(str[i_count]);
		i_count++;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i_count;

	i_count = 0;
	if (src == NULL)
		return (NULL);
	while (src[i_count] != '\0')
	{
		dst[i_count] = src[i_count];
		i_count++;
	}
	dst[i_count] = '\0';
	return (dst);
}

char	*ft_strdup(char *str)
{
	char			*ret;
	unsigned int	size_str;
	size_t			count;

	size_str = ft_strlen(str);
	ret = (char *)malloc((size_str + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (str[count] != '\0')
	{
		ret[count] = str[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
