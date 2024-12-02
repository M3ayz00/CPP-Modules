/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:28 by msaadidi          #+#    #+#             */
/*   Updated: 2024/12/02 16:47:45 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"
#include <cmath>
#include <limits.h>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& S)
{
  *this = S;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&  ScalarConverter::operator=(const ScalarConverter& S)
{
  (void)S;
  return (*this);
}

int ScalarConverter::isSpecialDouble(const std::string& literal)
{
  return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

int ScalarConverter::isSpecialFloat(const std::string& literal)
{
  return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isInt(const std::string& literal)
{
  char *end;
  std::strtol(literal.c_str(), &end, 10);
  return (*end == '\0');
}

bool ScalarConverter::isChar(const std::string& literal)
{
  return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isFloat(const std::string& literal)
{
  size_t  pos = literal.find("f");
  if (pos == std::string::npos || pos != literal.length() - 1) return (0);
  pos = literal.find(".");
  if (pos != std::string::npos)
    if (pos == 0 || pos == literal.length() - 1 || !std::isdigit(literal[pos - 1]) || !std::isdigit(literal[pos + 1])) return (0);
  char *end;
  std::strtof(literal.c_str(), &end);
  return (*end == 'f' && std::isdigit(*(end - 1)));
}

bool ScalarConverter::isDouble(const std::string& literal)
{
  size_t  pos = literal.find("f");
  if (pos != std::string::npos) return (0);
  pos = literal.find("e");
  if (pos != std::string::npos)
    if (std::isdigit(literal[pos - 1]) && (((literal[pos + 1] == '+' || literal[pos + 1] == '-') && std::isdigit(literal[pos + 2])) || std::isdigit(literal[pos + 1]))) return (1);
  pos = literal.find(".");
  if (pos == 0 || pos == literal.length() - 1 || !std::isdigit(literal[pos - 1]) || !std::isdigit(literal[pos + 1])) return (0);
  pos = literal.find(".", pos + 1);
  if (pos != std::string::npos) return (0);
  char *doubleEnd;
  std::strtof(literal.c_str(), &doubleEnd);
  return (*doubleEnd == '\0');
}

void  ScalarConverter::printChar(double value)
{
  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value) || value > CHAR_MAX || value < 0)  
    std::cout << "impossible\n";
  else if (!std::isprint(static_cast<char>(value)))
    std::cout << "non displayable\n";
  else
    std::cout << "\'" << static_cast<char>(value) << "\'\n";
}

void  ScalarConverter::printInt(double value)
{
  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(value) << "\n";
}

void  ScalarConverter::printDouble(double value)
{
  bool  tolerance = (fmod(value, 1.0f) || value > 1e5);
  std::cout << "double: ";
  if (std::isnan(value))  
    std::cout << "nan\n";
  else if (std::isinf(value))
    std::cout << (std::signbit(value) ? "-inf\n" : "+inf\n"); 
  else
    std::cout << value << (tolerance ? "\n" : ".0\n");
}


void  ScalarConverter::printFloat(double value)
{
  bool  tolerance = (fmod(static_cast<float>(value), 1.0f) || value > 1e5);
  std::cout << "float: ";
  if (std::isnan(static_cast<float>(value)))
    std::cout << "nanf\n";
  else if (std::isinf(static_cast<float>(value)))
    std::cout << (std::signbit(value) ? "-inff\n" : "+inff\n");
  else
    std::cout << static_cast<float>(value) << (tolerance ? "f\n" : ".0f\n");
}

bool  ScalarConverter::isDigit(const std::string& literal)
{
  return (isDouble(literal) || isInt(literal) || isFloat(literal)
    || isSpecialDouble(literal) || isSpecialFloat(literal));
}

void  ScalarConverter::convert(const std::string& literal)
{
  double  value = 0.0;
  if (isChar(literal))
    value = static_cast<double>(literal[0]);
  else if (isDigit(literal))
    value = std::strtod(literal.c_str(), NULL);
  else
  {
    std::cout << "Invalid literal\n";
    return ; 
  }
  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}