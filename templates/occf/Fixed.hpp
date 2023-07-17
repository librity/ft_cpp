/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 11:49:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
};

#endif
