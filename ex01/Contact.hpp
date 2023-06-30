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
		int			get_init(void);
		void		add_data(void);
		std::string	get_data(int index);
};

#endif