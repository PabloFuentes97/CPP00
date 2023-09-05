#include "Utils.hpp"

int		strIsDigit(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

std::string	getUserInput(void)
{
	std::string	input;

	std::cin.clear();
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(EXIT_FAILURE);
	return (input);
}