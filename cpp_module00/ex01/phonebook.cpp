#include "phonebook.hpp"

Contact::Contact() {}

void	Contact::set(const std::string &firstName, const std::string &lastName,
				const std::string &nickname, const std::string &phoneNumber,
				const std::string &darkestSecret) {
	this->FirstName = firstName;
	this->LastName = lastName;
	this->Nickname = nickname;
	this->PhoneNumber = phoneNumber;
	this->DarkestSecret = darkestSecret;
}

void	Contact::display_full() const{
	std::cout << "First Name: " << FirstName << std::endl;
	std::cout << "Last Name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone Number: " << PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << DarkestSecret << std::endl;

}

void	Contact::display_byidx(int idx) const{
	std::cout << std::setw(10) << idx << "|";
	std::cout << std::setw(10) << (FirstName.length() > 10 ? FirstName.substr(0, 9) + "." : FirstName) << "|";
	std::cout << std::setw(10) << (LastName.length() > 10 ? LastName.substr(0, 9) + "." : LastName) << "|";
	std::cout << std::setw(10) << (Nickname.length() > 10 ? Nickname.substr(0, 9) + "." : Nickname) << std::endl;
}

PhoneBook::PhoneBook() : cnt(0), idx(0) {}

void	PhoneBook::addContact() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	std::cout << "Enter first Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);

	contact[idx].set(firstName, lastName, nickname, phoneNumber, secret);
	idx = (idx + 1) % 8;
	if (cnt < 8)
		cnt++;
}

void	PhoneBook::search() const {
	if (!cnt) {
		std::cout << "No contacts available" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < cnt; i++)
		contact[i].display_byidx(i);

	std::cout << "Enter index to view details: ";
	int idx;
	std::cin >> idx;
	std::cin.ignore();
	if (idx >= 0 && idx < cnt)
		contact[idx].display_full();
	else
		std::cout << "Invalid index!" << std::endl;

}
