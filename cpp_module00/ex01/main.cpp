#include "phonebook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (!0) {
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd)) {
			std::cout << "\nInput interrupted." << std::endl;
			break;
		}
		if (cmd == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else if (cmd == "ADD")
			pb.addContact();
		else if (cmd == "SEARCH")
			pb.search();
		else if (!cmd.empty())
			std::cout << "Invalid command! Use ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}
