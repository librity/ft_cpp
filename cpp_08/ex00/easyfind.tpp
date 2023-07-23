/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/23 16:45:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char *NeedleNotFoundException::what(void) const throw()
{
	return "Couldn't find needle in the haaaaaaaaaaay";
}

template <typename T>
typename T::iterator easyfind(T &hay, int needle)
{
	typename T::iterator result = std::find(hay.begin(), hay.end(), needle);
	if (result == hay.end())
		throw NeedleNotFoundException();

	return result;
}
