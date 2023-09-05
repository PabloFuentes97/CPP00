#include <iostream>

int	main(int argc, char **argv)
{
	std::string	str;
	int			len;

	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1); }
	for (int i = 1; i < argc; i++){
		str = argv[i];
		len = str.length();
		for (int j = 0; j < len; j++){
			if (islower(str[j]))
				str[j] = std::toupper(str[j]);
		}
		std::cout << str; 
	}
	std::cout << std::endl;
	return (0);
}