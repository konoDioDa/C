#include <stdio.h>
#include <ctype.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]) {

	int i = 0;
	for (i = 0; i < argc; i++) {
		// attempting to make function [print_letters] uneccessary
		//print_letters(argv[i]);

		int j = 0;
		for (j = 0; argv[j] != '\0'; j++) {

			char *ch = argv[i];

			if (isalpha(ch) > 0) {
	
				printf("'%c' == %d", ch, ch);
			}
		}
		printf("\n");
	}
}

void print_letters(char arg[]) {

	int i = 0;
	for (i = 0; arg[i] != '\0'; i++) {
		char ch = arg[i];

// the following four lines render function [can_print_it] uneccessary
		if (isalpha(ch) > 0) {

			printf("'%c' == %d", ch, ch);
		}
	}
	printf("\n");
}

/*int can_print_it(char ch) {

	return isalpha(ch) || isblank(ch);
}*/

int main(int argc, char *argv[]) {

	print_arguments(argc, argv);
	return 0;
	}
