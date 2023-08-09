#include <string>
#include "Contact.hpp"
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

class	PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
		void	printTable(std::string dict[]);
	public:
		PhoneBook();
		~PhoneBook();
		Contact	getContact(int index);
		void	add();
		void	search(void);
		void	exit(void);
};

#endif