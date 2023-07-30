/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_stack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:16:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/07/30 14:33:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE: https://www.guru99.com/stack-in-cpp-stl.html
// c++ -Wall -Wextra -Werror -std=c++98 std_stack.cpp && ./a.out

#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	st.pop();
	st.pop();

	while (!st.empty())
	{
		cout << ' ' << st.top();
		st.pop();
	}
}

// #include <iostream>
// #include <stack>
// using namespace std;
// void createStack(stack<int> mystack)
// {
// 	stack<int> ms = mystack;
// 	while (!ms.empty())
// 	{
// 		cout << '\t' << ms.top();
// 		ms.pop();
// 	}
// 	cout << '\n';
// }
// int main()
// {
// 	stack<int> st;
// 	st.push(32);
// 	st.push(21);
// 	st.push(39);
// 	st.push(89);
// 	st.push(25);

// 	cout << "The stack st is: ";
// 	createStack(st);
// 	cout << "\n st.size() : " << st.size();
// 	cout << "\n st.top() : " << st.top();
// 	cout << "\n st.pop() : ";
// 	st.pop();
// 	createStack(st);
// 	return 0;
// }

// #include <iostream>
// #include <stack>
// #include <cstdlib>
// using namespace std;
// int main()
// {
// 	stack<int> st1;
// 	stack<int> st2;

// 	st1.emplace(12);
// 	st1.emplace(19);

// 	st2.emplace(20);
// 	st2.emplace(23);

// 	st1.swap(st2);

// 	cout << "st1 = ";
// 	while (!st1.empty())
// 	{
// 		cout << st1.top() << " ";
// 		st1.pop();
// 	}

// 	cout << endl << "st2 = ";
// 	while (!st2.empty())
// 	{
// 		cout << st2.top() << " ";
// 		st2.pop();
// 	}
// }

// #include <iostream>
// #include <stack>
// #include <cstdlib>
// using namespace std;
// int main()
// {
// 	stack<int> st;
// 	st.push(12);
// 	st.push(19);
// 	st.push(20);
// 	cout << st.top();
// 	cout << st.size();
// }
