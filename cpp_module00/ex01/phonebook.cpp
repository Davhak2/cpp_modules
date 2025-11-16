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

PhoneBook::PhoneBook() : cnt(0) {}

bool PhoneBook::isValidName(const std::string &name) const
{
	if (name.empty())
		return false;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!std::isalpha(name[i]))
			return false;
	}
	return true;
}

bool PhoneBook::isValidPhoneNumber(const std::string &phone) const
{
	if (phone.empty())
		return false;

	size_t start = 0;
	if (phone[0] == '+')
		start = 1;
	for (size_t i = start; i < phone.length(); i++)
	{
		if (!std::isdigit(phone[i]))
			return false;
	}
	return true;
}

bool PhoneBook::isDuplicate(const std::string &phoneNumber, const std::string &nickname) const
{
	for (int i = 0; i < cnt; i++)
	{
		if (contact[i].getNickname() == nickname) {
			std::cout << "Error: Nickname already exists!" << std::endl;
			return true;
		}
		if (contact[i].getPhoneNumber() == phoneNumber) {
			std::cout << "Error: Phone number already exists!" << std::endl;
			return true;
		}
	}
	return false;
}

void PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	do {
		std::cout << "Enter first name (alphabetic characters only): ";
		if (!std::getline(std::cin, firstName)) {
			std::cout << "\nInput interrupted." << std::endl;
			exit(0);
		}
		if (!isValidName(firstName))
			std::cout << "Invalid! First name must contain only alphabetic characters." << std::endl;
	} while (!isValidName(firstName));

	do {
		std::cout << "Enter last name (alphabetic characters only): ";
		if (!std::getline(std::cin, lastName)) {
			std::cout << "\nInput interrupted." << std::endl;
			exit(0);
		}
		if (!isValidName(lastName))
			std::cout << "Invalid! Last name must contain only alphabetic characters." << std::endl;
	} while (!isValidName(lastName));

	do {
		std::cout << "Enter nickname: ";
		if (!std::getline(std::cin, nickname)) {
			std::cout << "\nInput interrupted." << std::endl;
			exit(0);
		}
		if (nickname.empty())
			std::cout << "Nickname cannot be empty!" << std::endl;
	} while (nickname.empty());

	if (isDuplicate(phoneNumber, nickname)) {
		std::cout << "Contact not added due to duplicate information." << std::endl;
		return ;
	}

	do {
		std::cout << "Enter phone number (can start with +, then digits only): ";
		if (!std::getline(std::cin, phoneNumber)) {
			std::cout << "\nInput interrupted." << std::endl;
			exit(0);
		}
		if (!isValidPhoneNumber(phoneNumber))
			std::cout << "Invalid! Phone number can start with + followed by digits only." << std::endl;
	} while (!isValidPhoneNumber(phoneNumber));

	if (isDuplicate(phoneNumber, nickname)) {
		std::cout << "Contact not added due to duplicate information." << std::endl;
		return ;
	}

	do {
		std::cout << "Enter darkest secret: ";
		if (!std::getline(std::cin, secret)) {
			std::cout << "\nInput interrupted." << std::endl;
			exit(0);
		}
		if (secret.empty())
			std::cout << "Darkest secret cannot be empty!" << std::endl;
	} while (secret.empty());

	if (cnt < 8) {
		contact[cnt].set(firstName, lastName, nickname, phoneNumber, secret);
		cnt++;
	}
	else {
		for (int i = 0; i < 7; i++) {
			contact[i] = contact[i + 1];
		}
		contact[7].set(firstName, lastName, nickname, phoneNumber, secret);
	}

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search() const
{
	if (!cnt)
	{
		std::cout << "No contacts available!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < cnt; i++)
		contact[i].display_byidx(i);

	while (!0) {
		std::cout << "Enter index to search for a contact or type CANCEL: ";
		std::string input;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nInput interrupted. Exiting program." << std::endl;
			exit(0);
		}
		if (input == "CANCEL")
			return;
		if (input.empty())
			continue;
		bool isValidNumber = true;
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i])) {
				isValidNumber = false;
				std::cout << "Invalid index" << std::endl;
				break;
			}
		}

		if (!isValidNumber)
			continue;
		int idx = std::atoi(input.c_str());
		if (idx >= 0 && idx < cnt) {
			contact[idx].display_full();
			return;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
}
