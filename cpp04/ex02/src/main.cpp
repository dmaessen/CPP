/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:04 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/14 12:52:05 by dmaessen         ###   ########.fr       */
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
    std::cout << "---- PART 1 ----\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << '\n';
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    std::cout << '\n';
    delete(i);
    delete(j);
    
    std::cout << "\n---- PART 2 ----\n";
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

    std::cout << "\n---- PART 3 ----\n";
    Dog d;
    Dog d2;
    Dog d3(d);
    d2 = d;
    
    std::cout << '\n';
    std::cout << d.getType() << " " << std::endl;
    std::cout << d2.getType() << " " << std::endl;
    std::cout << d3.getType() << " " << std::endl;
    d.makeSound();
    d2.makeSound();
    d3.makeSound();
    std::cout << '\n';
    for (int x = 0; x < 100; x++) {
            d.getBrain().setIdeas("woof-woof ", x);
    }
    for (int x = 0; x < 100; x++) {
            std::cout << d.getBrain().getIdeas(x);
    }
    std::cout << '\n';
    
    return 0;
}

