#pragma once

#include <iostream>
#include <string>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	Contact();
	void set(const std::string &firstName, const std::string &lastName,
			 const std::string &nickname, const std::string &phoneNumber,
			 const std::string &darkestSecret);
	void display_byidx(int idx) const;
	void display_full() const;

	std::string getPhoneNumber() const { return PhoneNumber; }
	std::string getNickname() const { return Nickname; }
};
