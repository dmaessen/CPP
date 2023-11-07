#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
    int index;
	

public:
    Contact contact[8]; // or should this be of type array??
    int     count_contacts;
	void	cmd_add();
    // functions for add and search here??
};

#endif