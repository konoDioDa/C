#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 1) {
		printf("You don't have any arguments, you piece of shit.\n");
		} else if (argc > 0 && argc < 3) {
			printf("Here's your argument fuckr:\n");

		for (i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. Suck a fuck and get bent!\n");
	}
	return 0;
}
