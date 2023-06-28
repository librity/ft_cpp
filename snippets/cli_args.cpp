// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace	std;
int	main(int argc, char *argv[], char *envp[])
{
	bool numberLines = false; // Default is no line numbers.
	// If /n is passed to the .exe, display numbered listing
	// of environment variables.
	if ((argc == 2) && _stricmp(argv[1], "/n") == 0)
		numberLines = true;
	// Walk through list of strings until a NULL is encountered.
	for (int i = 0; envp[i] != NULL; ++i)
	{
		if (numberLines)
			cout << i << ": "; // Prefix with numbers if /n specified
		cout << envp[i] << "\n";
	}
}
