
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include "Contact.hpp"
#include "Utils.hpp"
#define MAXCONTACTS 8

class	PhoneBook
{
	private:
		Contact contacts[MAXCONTACTS];
		int		numContacts;
		int		oldestContact;
		void	printTable(void);
		int		validIndex(std::string input);
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search(void);
		void	exit(void);
		void	findCommand(std::string input);
};

#endif