#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "Constructor de contact" << std::endl;
	this->init = 0;
}

Contact::~Contact(void)
{
	std::cout << "Destructor de contact" << std::endl;
}

std::string	Contact::get_data(int index)
{
	return (this->data[index]);
}
void	Contact::add_data(void)
{
	std::string	dict[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string	buffer;
	int			i;

	i = 0;
	while (i < 5){
		std::cout << "Enter " << dict[i] << ": " << std::endl;
		std::cin >> buffer;
		if (!buffer.empty())
		{
			this->data[i].assign(buffer);
			i++;
		}
		buffer.clear();
	}
	this->init = 1;
}

int	Contact::get_init(void)
{
	return (this->init);
}
