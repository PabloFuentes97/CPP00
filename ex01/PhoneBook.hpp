#include <string>
#include "Contact.hpp"

#define MAXCONTACTS 8
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

class	PhoneBook
{
	private:
		Contact contacts[MAXCONTACTS];
		int		numContacts;
		int		oldestContact;
		void	printTable(std::string dict[]);
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search(void);
		void	exit(void);
};

#endif