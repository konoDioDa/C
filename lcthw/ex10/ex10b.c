#include <stdio.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {

		printf("ERROR: You need one argument.\n");
		// the following line aborts the program
		return 1;

	}
	
	int i = 0;
	// the '\0' on the line below is [NUL]
	for (i = 0; argv[1][i] != '\0'; i++) {

		char letter = argv[1][i];

		if (argv[1][i] == 'a' || argv[1][i] == 'A' || argv[1][i] == 'e' || argv[1][i] == 'E' || argv[1][i] == 'i' || argv[1][i] == 'I' || argv[1][i] == 'o' || argv[1][i] == 'O' || argv[1][i] == 'u' || argv[1][i] == 'U' ) {

			printf("%c is a vowel!\n", letter);

		} else if(argv[1][i] == 'y' || argv[1][i] == 'Y') {

			printf("%c is SOMETIMES a vowel...\n");

		} else {
		
			printf("%c is not a vowel!\n", letter);
			
		}
		
	}
}
