#include "phonebook.hpp"

Contact::Contact() {}

void Contact::set(const std::string &firstName, const std::string &lastName,
				  const std::string &nickname, const std::string &phoneNumber,
				  const std::string &secret)
{
	this->FirstName = firstName;
	this->LastName = lastName;
	this->Nickname = nickname;
	this->PhoneNumber = phoneNumber;
	this->DarkestSecret = secret;
}

void Contact::display_full() const
{
	std::cout << "First Name: " << FirstName << std::endl;
	std::cout << "Last Name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone Number: " << PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}

void Contact::display_byidx(int idx) const
{
	std::cout << std::setw(10) << idx << "|";
	std::cout << std::setw(10) << (FirstName.length() > 10 ? FirstName.substr(0, 9) + "." : FirstName) << "|";
	std::cout << std::setw(10) << (LastName.length() > 10 ? LastName.substr(0, 9) + "." : LastName) << "|";
	std::cout << std::setw(10) << (Nickname.length() > 10 ? Nickname.substr(0, 9) + "." : Nickname) << std::endl;
}
