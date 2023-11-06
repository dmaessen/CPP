#include <iostream>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	else
	{
		for (int i = 1;  i < argc; ++i)
		{
			for (size_t len = 0; len < strlen(argv[i]); len++)
				putchar(toupper(argv[i][len]));
		}
		std::cout << '\n';
	}
	return 0;
}
