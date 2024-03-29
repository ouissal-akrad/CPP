/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:10:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 20:25:05 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct data
{
	int		a;
	char	c;
}			t_data;

class Serializer
{
  private:
	Serializer();
	~Serializer();
  public:
	static uintptr_t serialize(t_data *ptr);
	static t_data *deserialize(uintptr_t raw);
};

#endif