/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:53:40 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 14:08:18 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "MEMORY ADDRESS\n";
    std::cout << "str: " << &str << "; stringPTR: " << stringPTR << "; stringREF: " << &stringREF << '\n';
    
    std::cout << '\n' << "VALUE\n";
    std::cout << "str: " << str << "; stringPTR: " << *stringPTR << "; stringREF: " << stringREF << '\n';
    
    return 0;
}