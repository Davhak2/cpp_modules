#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 4){
		std::cerr << "Usage: ./Sed_is_for_losers <filename> <s1> <s2>\n" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 is empty.\n";
		return 1;
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile) {
		std::cerr << "Error: cannot open input file.\n";
		return 1;
	}

	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile) {
		std::cerr << "Error: cannot open output file.\n";
		return 1;
	}

	std::string s;
	while (std::getline(inFile, s))
	{
		std::string result;
		size_t pos = 0;

		while (true)
		{
			size_t found = s.find(s1, pos);
			if (found == std::string::npos) {
				result += s.substr(pos);
				break;
			}
			result += s.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
		}

		outFile << result;
		if (!inFile.eof())
			outFile << std::endl;
	}

}
