/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:04 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 12:42:40 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* k = j;

    std::cout << '\n';
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    k->makeSound();
    std::cout << '\n';
    delete(i);
    delete(j);
    delete(k);

    std::cout << '\n';
    int n = 4;
    const Animal* a[n];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            a[i] = new Cat();
        else
            a[i] = new Dog();
    }
    
    std::cout << '\n';
    for (int i = 0; i < n; i++)
        a[i]->makeSound();

    std::cout << '\n';
    for (int i = 0; i < n; i++)
        delete a[i];

    // test the setting of the brain
    
    return 0;
}
