/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:25:07 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 02:33:18 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_bzero(void *s, size_t n)
{
	unsigned char *temp;
	size_t i;

	temp = s;
	i = 0;
	while (i < n)
	{
		*temp = 0;
		temp++;
		i++;
	}
}
