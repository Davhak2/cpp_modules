#include <iostream>
#include <string>
#include <cctype>

void	print_str(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
		std::cout << (char)std::toupper(s[i]);
}

int	main(int argc, char **argv){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++)
			print_str(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}
