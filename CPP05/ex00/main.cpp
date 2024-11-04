/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/23 13:43:52 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat *B1 = new Bureaucrat[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2)
        {
            try
            {
                B1[i] = Bureaucrat("Police Officer", i * 10);
            }
            catch (const GradeTooHighException& e)
            {
                std::cout << e.what() << std::endl;
            }
            catch (const GradeTooLowException &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << B1[i];
        }
        else
        {
            try
            {
                B1[i] = Bureaucrat("Fireman", i * 10);
            }
            catch (const GradeTooHighException& e)
            {
                std::cout << e.what() << std::endl;
            }
            catch (const GradeTooLowException &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << B1[i];
        }
    }

    // Bureaucrat* B1;
    // try
    // {
    //     B1 = new Bureaucrat("Police 0fficer", 2);
    // }
    // catch (const GradeTooHighException& e)
    // {
    //     std::cout<< e.what();
    //     return (1);
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cout << e.what();
    //     return (1);
    // }
    // std::cout << *B1;
    // try
    // {
    //     B1->decGrade();
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cout << e.what();
    //     return (1);
    // }
    // catch (const GradeTooHighException& e)
    // {
    //     std::cout<< e.what();
    //     return (1);
    // }
    // std::cout << *B1;
    // Bureaucrat* B2;
    // try
    // {
    //     B2 = new Bureaucrat("Fireman", 1);
    // }
    // catch (const GradeTooHighException& e)
    // {
    //     std::cout<< e.what();
    //     return (1);
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cout << e.what();
    //     return (1);
    // }
    // std::cout << *B2;
    // try
    // {
    //     B2->incGrade();
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cout << e.what();
    //     return (1);
    // }
    // catch (const GradeTooHighException& e)
    // {
    //     std::cout << e.what();
    //     return (1);
    // }
    // std::cout << *B2;
    // delete B1;
    // delete B2;
    // return (0);
}