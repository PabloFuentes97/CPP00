#include <iostream>

int	main(int argc, char **argv)
{
	int			i;
	std::string	str;
	int			len;
	i = 1;
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1); }
	while (argv[i]) {
		str = str.assign(argv[i]);
		len = str.length();
		for (int j = 0; j < len; j++){
			if (islower(str[j]))
				str[j] = std::toupper(str[j]);
			}
		std::cout << str; 
		i++; }
	std::cout << std::endl;
	return (0);
}