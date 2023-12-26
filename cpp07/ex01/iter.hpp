/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:43:27 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/26 23:47:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	fun(const T &t)
{
	std::cout << t << std::endl;
}
template <typename T, typename U>
void	iter(T *tab, int size, U fun)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		fun(tab[i]);
		i++;
	}
}
#endif