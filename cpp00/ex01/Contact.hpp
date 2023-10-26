#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

void cmd_add();
void print_contactinfo(Contact newcontact);

class Contact
{
private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Nickname;
	std::string m_PhoneNb;
	std::string m_Secret;

public:
    void setFirstName(std::string input) {
        m_FirstName = input;
    }
    void setLastName(std::string input) {
        m_LastName = input;
    }
    void setNickname(std::string input) {
        m_Nickname = input;
    }
    void setPhoneNb(std::string input) {
        m_PhoneNb = input;
    }
    void setSecret(std::string input) {
        m_Secret = input;
    }
    
    //void setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNb, std::string Secret);

    std::string getFirstName() const { return m_FirstName; } // const ?? ++ get or set??
    std::string getLastName() const { return m_LastName; }
    std::string getNickname() const { return m_Nickname; }
	std::string getPhoneNb() const { return m_PhoneNb; }
	std::string getSecret() const { return m_Secret; }
};

#endif