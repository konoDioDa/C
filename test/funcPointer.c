#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {

	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}


typedef int (*twoInt_ti) (int a, int b);

int funcMath(twoInt_ti num) {
	printf("Woah! Function dawg!");


}





int main(int argc, char *argv[]) {





	printf("Hi Ben!\n");
	funcMath;
}

