/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:34:01 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/24 20:33:16 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str:			" << &str << std::endl;
	std::cout << "Memory address held by stringPTR:	" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:	" << &stringREF << std::endl;

	std::cout << "Value of of str:		" << str << std::endl;
	std::cout << "Value pointed to by stringPTR:	" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:	" << stringREF << std::endl;
	return 0;
}