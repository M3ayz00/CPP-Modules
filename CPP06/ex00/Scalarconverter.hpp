/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalarconverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:52:56 by msaadidi          #+#    #+#             */
/*   Updated: 2024/11/29 15:22:11 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define ERR_PRINT() std::cout << "char: 'impossible'\nint: impossible\nfloat: impossible\ndouble: impossible\n";

class ScalarConverter
{
  private :
    static int   isDigit(const std::string& literal);
    static int   isSpecialDouble(const std::string& literal);
    static int   isSpecialFloat(const std::string& literal);
    static bool  isInt(const std::string& literal);
    static bool  isChar(const std::string& literal);
    static bool  isFloat(const std::string& literal);
    static bool  isDouble(const std::string& literal);
    static void  printChar(double value);
    static void  printInt(double value);
    static void  printDouble(double value);
    static void  printFloat(double value);
    static void  convert(const std::string& literal);

  public  :
    ScalarConverter();
    ScalarConverter(const ScalarConverter& S);
    ~ScalarConverter();
    ScalarConverter&  operator=(const ScalarConverter& S);
  
};

#endif