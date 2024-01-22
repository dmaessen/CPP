/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:00 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 10:32:40 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void		Replace::setS1(std::string input) {
	m_s1 = input;
}

std::string	Replace::getS1() const {
	return m_s1;
}

void		Replace::setS2(std::string input) {
	m_s2 = input;
}

std::string	Replace::getS2() const {
	return m_s2;
}

