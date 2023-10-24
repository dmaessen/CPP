#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
private:
    std::string m_FirstName{};
    std::string m_LastName{};
    std::string m_Nickname{};
	std::string m_PhoneNb{};
	std::string m_Secret{};

public:
    Contact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNb, std::string Secret);

    void SetContact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNb, std::string Secret);

    std::string getFirstName() const { return m_FirstName; }
    std::string getLastName() const { return m_LastName; }
    std::string getNickname() const { return m_Nickname; }
	std::string getPhoneNb() const { return m_PhoneNb; }
	std::string getSecret() const { return m_Secret; }
};

#endif