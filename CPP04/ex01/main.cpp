/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:58:36 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/21 15:04:42 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    {
        const Animal* meta[100];
        for(int i = 0; i < 100; i++)
        {
            if (i < 50)
                meta[i] = new Cat();
            else
                meta[i] = new Dog();
        }
        for (int i = 0; i < 100; i++)
            delete meta[i];
    }
    {
        Dog* D = new Dog();
        for (int i = 0; i < 100; i++)
        {
            std::cout << D->getIdea(i) << std::endl;
            D->setIdea("pixou " + to_string(i + 1), i);
            std::cout << D->getIdea(i) << std::endl;
        }
        Dog D1 = *D;
        Cat *C = new Cat();
        for (int i = 0; i < 100; i++)
        {
            std::cout << C->getIdea(i) << std::endl;
            C->setIdea("appah " + to_string(i + 1), i);
            std::cout << C->getIdea(i) << std::endl;
        }
        Cat C1 = *C;
        delete D;
        delete C;
        for (int i = 0; i < 100; i++)
        {
            std::cout << D1.getIdea(i) << std::endl;
            std::cout << C1.getIdea(i) << std::endl;
        }
    }
    {
        Dog dog;
        {
            Dog tmp = dog;
        }
    }
}