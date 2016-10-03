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
		
		switch (letter) {

			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;
			
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'y':
			case 'Y':
				if (i > 2) {
					// it's only sometime Y
					printf("%d: 'Y\n", i);
				}
				break;
			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}
	/*for (i = 0; argv[1][i] != 'b', argv[1][i] != 'B', argv[1][i] != 'c', argv[1][i] != 'C', argv[1][i] != 'd', argv[1][i] != 'D', argv[1][i] != 'f', argv[1][i] != 'F'; i++) {

		char letter = argv[1][i];
		printf("%c is a consonant\n", letter);
		} */

}
