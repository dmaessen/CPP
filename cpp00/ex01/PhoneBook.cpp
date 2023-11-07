#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void PhoneBook::cmd_add()
{
	Contact newcontact;
	std::string input;
	// index needed ??
	
	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setPhoneNb(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setSecret(input);

	std::cout << newcontact.getFirstName() << '\n';
    std::cout << newcontact.getLastName() << '\n';
    std::cout << newcontact.getNickname() << '\n';
    std::cout << newcontact.getPhoneNb() << '\n';
    std::cout << newcontact.getSecret() << '\n';

	
    // print_contactinfo(newcontact);
	// maybe extra field to see which contact has been added last for overwritting??
	// now add new to the phonebook list, checking if it needs to overwrite the oldest
}

// void Contact::print_contactinfo(Contact newcontact)
// {
//     std::cout << newcontact.getFirstName() << '\n'; // do i need newcontact here?? bit confused
//     std::cout << newcontact.getLastName() << '\n';
//     std::cout << newcontact.getNickname() << '\n';
//     std::cout << newcontact.getPhoneNb() << '\n';
//     std::cout << newcontact.getSecret() << '\n';
// }








// ft to check the amount of contacts already

// NICE EXAMPLE I THINK
// class FEE
// {
//     private:
//     int fee;
//     public:
//     void setfee()
//     {
//         cout<<"Enter the monthly fee= ";
//         cin>>fee;
//     }
//     void showfee()
//     {
//         cout<<"Monthly fee is "<<fee<<endl;
//     }
// };

// int main()
// {
//     FEE stu[5];
//     for(int i=0;i<5;i++)
//     {
//         if(i==0)
//         stu[i].setfee();
//         stu[i].showfee();
//     }
// }