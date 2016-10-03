#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {

	int usrInput;
	float floorInput = 450.25;
	int inputLen, logTest, absTest, floorTest;

	printf("Please input an integer...\n");
	scanf("%li", &usrInput);

	logTest = log10(usrInput);
	printf("Log to base 10 of [usrInput] is: %d...\n", logTest);

	absTest = labs(usrInput);
	printf("The absolute value of [usrInput] is: %d...\n", absTest);

	floorTest = floor(floorInput);
	printf("The rounded down value of [floorInput] is: %d...\n", floorTest);
	
}
