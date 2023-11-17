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
