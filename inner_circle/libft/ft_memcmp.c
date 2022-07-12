/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:23:25 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 11:39:43 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;
	size_t i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		p1++;
		p2++;
		i++;
	}
	return(0);
}
