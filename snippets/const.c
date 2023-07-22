/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:08:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/22 02:21:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang const.c && ./a.out

#include "stdio.h"

struct MutableInt
{
	int value;
};

int main(void)
{
	printf("Pointer to const:\n");
	const int a = 2;
	int *a_ptr = (int *)&a;
	printf("a = %d\n", a);
	*a_ptr = 42;
	printf("a = %d\n", a);
	printf("=================\n");

	printf("Non-const cast:\n");
	const struct MutableInt b = {5};
	printf("b.value = %d\n", b.value);
	((struct MutableInt *)&b)->value = 10;
	printf("b.value = %d\n", b.value);
	printf("=================\n");

	return 0;
}
