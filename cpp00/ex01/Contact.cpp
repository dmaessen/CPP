/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:29 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/13 12:16:25 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::setFirstName(std::string input) {
	m_FirstName = input;
}

void Contact::setLastName(std::string input) {
	m_LastName = input;
}

void Contact::setNickname(std::string input) {
	m_Nickname = input;
}

void Contact::setPhoneNb(std::string input) {
	m_PhoneNb = input;
}

void Contact::setSecret(std::string input) {
	m_Secret = input;
}

std::string Contact::getFirstName() const {
	return m_FirstName;
}

std::string Contact::getLastName() const {
	return m_LastName;
}

std::string Contact::getNickname() const {
	return m_Nickname;
}

std::string Contact::getPhoneNb() const {
	return m_PhoneNb;
}

std::string Contact::getSecret() const {
	return m_Secret;
}
