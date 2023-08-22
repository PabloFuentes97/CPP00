#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void	getUserInput(PhoneBook *book)
{
	std::string	input;

	std::cin.clear();
	std::cout << "Introduce an input: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		std::exit(1);
	if (input.empty())
		return ;
	if (!input.compare("ADD"))
		book->add();
	else if (!input.compare("SEARCH"))
	{
		book->search();
	}
	else if (!input.compare("EXIT"))
		book->exit();
	else
		std::cout << "Invalid input" << std::endl;
}

int	main(void)
{
	PhoneBook p;
	std::cout << "Commands: ADD, SEARCH and EXIT" << std::endl;
	while (1)
	{
		getUserInput(&p);
	}
	return (0);
}
