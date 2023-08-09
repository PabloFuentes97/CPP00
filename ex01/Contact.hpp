#include <string>

#ifndef CONTACT_HPP
#define CONTACT_HPP

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
		void		printInfo(std::string dict[]);
};

#endif