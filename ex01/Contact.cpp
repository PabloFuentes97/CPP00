#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) : init(0)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::getData(int index)
{
	return (this->data[index]);
}

int	checkValidData(std::string buffer, int index)
{
	int	i;

	if (index == 3)
	{
		if (buffer.length() != 9)
			return (0);
		for (i = 0; i < buffer.length(); i++)
			if (!isdigit(buffer[i]))
				return (0);
	}
	else
	{
		for (i = 0; i < buffer.length(); i++)
			if (isdigit(buffer[i]))
				return (0);
	}
	return (1);
}

void	Contact::setData(void)
{
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string	input;
	int			i;

	i = 0;
	for (int i = 0; i < 5; i++){
		std::cout << "Enter " << dict[i] << ": " << std::endl;
		input = getUserInput();
		while (input.empty() || !checkValidData(input, i))
		{
			std::cout << "Enter " << dict[i] << ": " << std::endl;
			std::cin >> input;		
		}
		this->data[i].assign(input);
	}
	this->init = 1;
}

int	Contact::getInit(void)
{
	return (this->init);
}

void	Contact::printInfo()
{
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	
	for (int i = 0; i < 5; i++)
		std::cout << dict[i] << ": " << this->getData(i) << std::endl;
}
