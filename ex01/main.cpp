#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utils.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook p;
	std::string	input;

	std::cout << "Commands: ADD, SEARCH and EXIT" << std::endl;
	while (1)
	{
		std::cout << "Introduce an input: " << std::endl;
		input = getUserInput();
		p.findCommand(input);
	}
	return (0);
}
