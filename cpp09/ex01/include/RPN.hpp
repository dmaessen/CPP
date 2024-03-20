/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:50:37 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/20 14:11:51 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<int> _stack;
	
	public:
		RPN(void);
        ~RPN();
        RPN(const RPN &src); // copy constructor
        RPN& operator=(const RPN &src); // assignment

		int checkArgv(char *argv);
		int calculation(char *argv);
	
};

#endif