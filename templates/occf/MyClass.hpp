/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyClass.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:08:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/17 12:24:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

class MyClass
{

public:
	MyClass();
	MyClass(const MyClass &my_class);
	~MyClass();
	MyClass &operator=(const MyClass &my_class);
};

#endif
