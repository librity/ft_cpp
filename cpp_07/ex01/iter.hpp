/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 21:21:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *arr, size_t length, void (*f)(const T &))
{
	size_t i = 0;
	while (i < length)
	{
		f(arr[i]);
		i++;
	}
}

template <typename T>
void iter(T *arr, size_t length, void (*f)(T &))
{
	size_t i = 0;
	while (i < length)
	{
		f(arr[i]);
		i++;
	}
}

#endif
