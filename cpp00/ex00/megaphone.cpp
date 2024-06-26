/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:21 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/21 17:00:58 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	else
	{
		for (int i = 1;  i < argc; ++i)
		{
			for (size_t len = 0; len < std::strlen(argv[i]); len++)
				std::putchar(std::toupper(argv[i][len]));
		}
		std::cout << '\n';
	}
	return 0;
}
