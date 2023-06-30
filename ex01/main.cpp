#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void	get_user_input(PhoneBook *book)
{
	std::string	input;

	std::cin.clear();
	std::cout << "Introduzca un input" << std::endl;
	std::cin >> input;
	std::cout << "Su input: " << input << std::endl;
	if (input.empty())
		return ;
	if (!input.compare("ADD"))
		book->add();
	else if (!input.compare("SEARCH"))
	{
		std::cout << "Introduzca un índice" << std::endl;
		std::cin >> input;
		book->search(std::stoi(input));
	}
		
	else if (!input.compare("EXIT"))
		book->exit();
	else
		std::cout << "Input erróneo" << std::endl;
}

int	main(void)
{
	PhoneBook p;
	while (1)
	{
		get_user_input(&p);
	}
	return (0);
}
