#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor de PhoneBook" << std::endl;
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor de PhoneBook" << std::endl;
}


void 	PhoneBook::add(void)
{
	std::cout << "Índice: " << this->index << std::endl;
	std::cout << "Terminó todo" << std::endl;
	if (this->index == 7)
		this->contacts[this->index].~Contact();
	this->contacts[this->index].add_data();
	if (this->index < 7)
		this->index++;
}

void	PhoneBook::search(int index)
{	
	if (this->contacts[index].get_init() == 0)
	{
		std::cout << "Contact doesn't exist" << std::endl;
		return ;
	}
	int i;
	int	j;
	std::cout << "     ";
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < (10 - dict[i].length()); j++)
			std::cout << " ";
		std::cout << dict[i] << " ";
		std::cout << "|";
	}
	std::cout << std::endl;
	for (i = 0; i < 5; i++){
		std::cout << dict[i] << ": " << this->contacts[index].get_data(i) << std::endl;
	}
}

void	PhoneBook::exit(void)
{

}
