#pragma once

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>

class PhoneBook
{
private:
	Contact contact[8];
	int cnt;

	bool isValidName(const std::string &name) const;
	bool isValidPhoneNumber(const std::string &phone) const;
	bool isDuplicate(const std::string &phoneNumber, const std::string &nickname) const;

public:
	PhoneBook();
	void addContact();
	void search() const;
};
