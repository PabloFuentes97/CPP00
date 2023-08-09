#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	this->init = 0;
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
	std::string	buffer;
	int			i;

	i = 0;
	while (i < 5){
		std::cout << "Enter " << dict[i] << ": " << std::endl;
		std::cin >> buffer;
		if (std::cin.eof())
			std::exit(1);
		while (buffer.empty() || !checkValidData(buffer, i))
		{
			std::cout << "Enter " << dict[i] << ": " << std::endl;
			std::cin >> buffer;		
		}
		this->data[i].assign(buffer);
		i++;
		buffer.clear();
	}
	this->init = 1;
}

int	Contact::getInit(void)
{
	return (this->init);
}

void	Contact::printInfo(std::string dict[])
{
	for (int i = 0; i < 5; i++)
		std::cout << dict[i] << ": " << this->getData(i) << std::endl;
}
