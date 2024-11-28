/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalarconverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:52:56 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/28 14:00:59 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define ERR_PRINT() std::cout << "char: 'impossible'\nint: impossible\nfloat: impossible\ndouble: impossible\n";

class ScalarConverter
{
  private :
    static int hasDecimal(const std::string& arg, char c);
    static int isDigit(const std::string& arg);

  public  :
    ScalarConverter();
    ScalarConverter(const ScalarConverter& S);
    ~ScalarConverter();
    ScalarConverter&  operator=(const ScalarConverter& S);
  
    static void  convert(const std::string &literal);
};

#endif