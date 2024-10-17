/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:09:47 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/17 14:14:15 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "The memory address of str : " << &str << "\n";
	std::cout << "The memory address held by stringPTR : " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF : " << &stringREF << "\n";

	std::cout << "The value of str : " << str << "\n";
	std::cout << "The value pointed by stringPTR : " << *stringPTR << "\n";
	std::cout << "The value pointed by strinREF : " << stringREF << "\n";

}
