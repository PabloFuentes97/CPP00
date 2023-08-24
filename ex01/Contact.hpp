#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include "Utils.hpp"

class Contact
{
	private:
		std::string	data[5];
		int			init;
	public:
		
		Contact(void);
		~Contact(void);
		int			getInit(void);
		void		setData(void);
		std::string	getData(int index);
		void		printInfo();
};

#endif