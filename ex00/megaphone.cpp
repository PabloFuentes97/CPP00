#include <iostream>

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1); }
	while (argv[i]) {
		for (int j = 0; j < std::strlen(argv[i]); j++){
			if (islower(argv[i][j]))
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i][j]; }
		i++; }
	std::cout << std::endl;
	return (0);
}