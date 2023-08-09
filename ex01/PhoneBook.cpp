#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void 	PhoneBook::add(void)
{
	if (this->index == 7)
		this->contacts[this->index].~Contact();
	this->contacts[this->index].setData();
	if (this->index < 7)
		this->index++;
}

void	PhoneBook::printTable(std::string dict[])
{
	std::string	print;
	int	spaces;

	std::cout << "     ";
	for (int i = 0; i < 3; i++)
		std::cout << std::setw(10) << std::right << dict[i] << " |";
	std::cout << std::endl;
	int i = 0;
	while (i < 8 && this->contacts[i].getInit() != 0)
	{
		std::cout << std::setw(5) << std::left << i;
		for (int j = 0; j < 3; j++)
		{
			print = this->contacts[i].getData(j);
			if (print.length() >= 10)
				print = print.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << print << "  ";
		}
		std::cout << std::endl;
		i++;
	}
}

int		strIsDigit(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	PhoneBook::search(void)
{	
	int			index;
	std::string	input;
	int 		i;
	int			j;
	int			spaces;
	std::string	print;

	if (this->index == 0)
	{
		std::cout << "No contacts added" << std::endl;
		return ;
	}
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	this->printTable(dict);
	std::cout << "Introduce an index: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		std::exit(1);
	if (!strIsDigit(input))
		return ;
	index = std::stoi(input);
	if (index >= 8)
	{
		std::cout << "Index surpass max number of contacts" << std::endl;
		return ;
	}
	if (this->contacts[index].getInit() == 0)
	{
		std::cout << "Contact doesn't exist" << std::endl;
		return ;
	}
	this->contacts[index].printInfo(dict);
}

void	PhoneBook::exit(void)
{
	std::exit(0);
}
