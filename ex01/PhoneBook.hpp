#include <string>
#include "Contact.hpp"
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

class	PhoneBook
{
	private:
		Contact contacts[7];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		Contact	get_contact(int index);
		void	add();
		void	search(int index);
		void	exit(void);
};

#endif