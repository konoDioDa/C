#include <stdio.h>
int main(int argc, char *argv[]) {

	if (argc == 1) {
		printf("You need to enter an argument when running this program...\n");


	} else {
		int humArgc = argc - 1;
		printf("You specified %d arguments at run time\n\n", humArgc);

		printf("The first argument will become an array, and NUL will be appended to the end\n\n");

		//printf("%s", argv[1]);
		//int *firstArgLen[sizeof(argv[1]) / sizeof(int)];
		//	printf("%d\n", sizeof(argv[0]));
		//	printf("%d\n", sizeof(argv[1]));
		//	printf("%s\n", argv[0]);
		//	printf("%s\n", argv[1]);
				
	}

}
