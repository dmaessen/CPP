/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:50:31 by dmaessen          #+#    #+#             */
/*   Updated: 2024/04/15 10:49:44 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN(void) {
    // std::cout << "Default constructor called\n";
}

RPN::~RPN(){
    // std::cout << "Destructor called\n";
}

RPN::RPN(const RPN &src) {
    // std::cout << "Copy constructor called\n";
    *this = src;
}

RPN& RPN::operator=(const RPN &src) {
    //std::cout << "Copy assignment operator called\n";
     if (this != &src)
        *this = src;
    return (*this);
}

int RPN::checkArgv(char *argv) {
	int nb = 0;
	for (int i = 0; !argv[i]; i++) {
		if (argv[i] == ' ' || argv[i] == '*' || argv[i] == '/'
		|| argv[i] == '+' || argv[i] == '-')
			continue ;
		else if (argv[i] > 47 && argv[i] < 58)
			nb++;
		else {
			std::cout << "Error: only operations with these tokens: '+ - / *' handled\n";
			return 1;
		}
	}
	if (nb > 9) {
		std::cout << "Error: expression must contain less than 10 numbers\n";
		return 1;
	}
	return 0;
}

int RPN::calculation(char *argv) {
	std::istringstream str(argv);
	std::string input;
	
	int nb;
	int res;
	while (str >> input) {
		if (input == "*" || input == "/" || input == "+" || input == "-") {
			if (_stack.size() < 2) {
				std::cout << "Error: incorrect expression\n";
				return 1;
			}
			int second = _stack.top();
			_stack.pop(); // rm from top of stack
			int first = _stack.top();
			_stack.pop();
			if (input == "*")
				res = first * second;
			else if (input == "+")
				res = first + second;
			else if (input == "-")
				res = first - second;
			else if (input == "/" && second != 0)
				res = first / second;
			else if (input == "/" && second == 0) {
				std::cout << "Error: impossible to divide by 0\n";
				return 1;
			}
			_stack.push(res);
		}
		else {
			nb = atoi(input.c_str());
			_stack.push(nb);
		}
		// std::stack<int> temp;
		// temp = _stack;
		// while (!temp.empty()) {
        // 	std::cout << temp.top() << ' ';
		// 	temp.pop();
		// }
		// std::cout << "\n";
	}
	if (_stack.size() != 1) { 
		std::cout << "Error: incorrect expression\n";
		return 1;
	}
	std::cout << _stack.top() << "\n";
	return 0;
}
