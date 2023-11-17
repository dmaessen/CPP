#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <iostream>

class Replace
{
	private:
		std::string m_s1;
		std::string m_s2;

	public:
		Replace(void) = default;
		~Replace(void) = default;

		void		setS1(std::string input);
        std::string	getS1() const;
		void		setS2(std::string input);
        std::string	getS2() const;
};

#endif