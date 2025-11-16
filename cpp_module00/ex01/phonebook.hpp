#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	public:
		Contact();
		void	set(const std::string &firstName, const std::string &lastName,
				const std::string &nickname, const std::string &phoneNumber,
				const std::string &darkestSecret);
		void	display_byidx(int idx) const;
		void	display_full() const;
};

class PhoneBook {
	private:
		Contact	contact[8];
		int		cnt;
		int		idx;
	public:
		PhoneBook();
		void addContact();
		void search() const;
};
