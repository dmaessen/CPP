#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
private:
	std::string	m_FirstName;
	std::string	m_LastName;
	std::string	m_Nickname;
	std::string	m_PhoneNb;
	std::string	m_Secret;

public:
	void		setFirstName(std::string input);
	void		setLastName(std::string input);
	void		setNickname(std::string input);
	void		setPhoneNb(std::string input);
	void		setSecret(std::string input);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNb() const;
	std::string	getSecret() const;
};

#endif