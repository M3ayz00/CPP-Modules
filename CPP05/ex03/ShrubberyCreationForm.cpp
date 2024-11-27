/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 03:51:46 by m3ayz00           #+#    #+#             */
/*   Updated: 2024/11/27 15:40:35 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation form", 145, 137), target("default")
{
  std::cout << "ShrubberyCreation default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm("Shrubbery creation form", 145, 137), target(_target)
{
  std::cout << "ShrubberyCreation constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& SCF) : AForm(SCF.getName(), SCF.getSignGrade(), SCF.getExecGrade()), target(SCF.target)
{
  std::cout << "ShrubberyCreation copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreation destructor called\n";
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& SCF)
{
  std::cout << "ShrubberyCreation assignment operator called\n";
  if (this != &SCF)
    target = SCF.target; 
  return (*this);
}

void  ShrubberyCreationForm::executeAction() const
{
  std::ofstream outFile((target + "_shrubbery").c_str()); 
  if (outFile.is_open())
  {
    outFile << "              _{\\ _{\\{\\/}/}/}__\n"
         << "             {/{/\\}{/{/\\}(\\}{/{/\\} _\n"
         << "            {/{/\\}{/{/\\}(_){}{/{/\\}  _\n"
         << "         {\\{/\\(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
         << "        {/{/(_)/}{\\{/\\)\\}{\\(_){/}/}/}/}\n"
         << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}/}\n"
         << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
         << "      _{\\{/{\\{/(_){}/}{/{/{/\\}\\})\\}{/\\}\n"
         << "     {/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}\n"
         << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
         << "       {/{\\{\\/}{/{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
         << "      {/{\\{\\/}{/){\\{\\/}/}{\\{\\(/}/}\\}/}\n"
         << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
         << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
         << "          (_){/{\\/}{\\{\\/}/}{\\}(_){\\/}\n"
         << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
         << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
         << "              {){/ {\\/}{\\/} \\}\\}\n"
         << "              (_)  \\.-'.-/\n"
         << "          __...--- |-'.-'| --...__\n"
         << "   _...--\"   .-'   |-'.-'|  ' -.  \"\"--..\n"
         << " -\"    ' .  . '    |.'-._| '  . .  '   \n"
         << " .  '-  '    .--'  | '-.'|    .  '  . '\n"
         << "          ' ..     |'-_.-|\n"
         << "  .  '  .       _.-|-._ -|-._  .  '  .\n"
         << "              .'   |'- .-|   '.\n"
         << "  ..-'   ' .  '.   `-._.-   .'  '  - .\n"
         << "   .-' '        '-._______.-'     '  .\n"
         << "        .      ~,\n"
         << "    .       .   |\\   .    ' '-.\n";
    outFile.close();
  }
}

