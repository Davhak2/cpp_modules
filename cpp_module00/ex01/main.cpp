#include "phonebook.hpp"


void add(PhoneBook &pb) {
	pb.addContact();
}

void search(PhoneBook &pb) {
	pb.search();
}

int main() {
	PhoneBook	pb;
	std::string	cmd;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	while (!0) {
		std::cout << "Enter command: " << std::endl;
		std::getline(std::cin, cmd);

		if (cmd == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else if (cmd == "ADD")
			add(pb);
		else if (cmd == "SEARCH")
			search(pb);
		else if (!cmd.empty())
			std::cout << "Invalid command! Use ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}
