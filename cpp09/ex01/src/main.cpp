/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:50:34 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/20 14:19:19 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: wrong amount of arguments\n";
		return 1;
	}
	
	RPN r;
	if (r.checkArgv(argv[1]))
		return 1;
	r.calculation(argv[1]);

	return 0;
}