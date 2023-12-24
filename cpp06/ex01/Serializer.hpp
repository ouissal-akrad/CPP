/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:10:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/12/24 17:19:24 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER
# define SERIALIZER

# include <iostream>
#include <sys/_types/_uintptr_t.h>

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