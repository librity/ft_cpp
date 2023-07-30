/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:56:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 14:03:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename T>
void Span::copy_range(T range_start, T range_end)
{
	if (std::distance(range_start, range_end) > (long int)space_left())
		throw CopyRangeException();

	while (range_start != range_end)
	{
		container.push_back(*range_start);
		range_start++;
	}

	sort();
}

#endif
