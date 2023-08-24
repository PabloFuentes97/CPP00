#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->numContacts = 0;
	this->oldestContact = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void 	PhoneBook::add(void)
{
	if (this->numContacts == MAXCONTACTS)
	{
		this->contacts[this->oldestContact].~Contact();
		this->contacts[this->oldestContact].setData();
		this->oldestContact++;
		if (this->oldestContact == MAXCONTACTS)
			this->oldestContact = 0;
	}
	else if (this->numContacts < MAXCONTACTS)
	{
		this->contacts[this->numContacts].setData();
		this->numContacts++;
	}
}

void	PhoneBook::printTable()
{
	std::string	print;
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	std::cout << "     ";
	for (int i = 0; i < 3; i++)
		std::cout << std::setw(10) << std::right << dict[i] << " |";
	std::cout << std::endl;
	int i = 0;
	while (i < MAXCONTACTS && this->contacts[i].getInit() != 0)
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

void	PhoneBook::findCommand(std::string input)
{
	if (!input.compare("ADD"))
		this->add();
	else if (!input.compare("SEARCH"))
		this->search();
	else if (!input.compare("EXIT"))
		this->exit();
	else
		std::cout << "Command doesn't exist!" << std::endl;
}

int	PhoneBook::validIndex(std::string input)
{
	int		index;
	int		input_len = input.length();
	char	index_c[input_len];
	if (!strIsDigit(input))
	{
		std::cout << "No number introduced" << std::endl;
		return (-1);
	}
	strcpy(index_c, input.c_str());
	index = std::atoi(index_c);
	if (index < 0 || index >= MAXCONTACTS)
	{
		std::cout << "Index out of range" << std::endl;
		return (-1);
	}
	if (this->contacts[index].getInit() == 0)
	{
		std::cout << "Contact doesn't exist" << std::endl;
		return (-1);
	}
	return (index);
}

void	PhoneBook::search(void)
{	
	int			index;
	std::string	input;

	if (this->numContacts == 0)
	{
		std::cout << "No contacts added" << std::endl;
		return ;
	}
	this->printTable();
	std::cout << "Introduce an index: " << std::endl;
	input = getUserInput();
	index = validIndex(input);
	if (index >= 0)
		this->contacts[index].printInfo();
}

void	PhoneBook::exit(void)
{
	std::exit(0);
}
