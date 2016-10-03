#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {


	char testString[20];	
	printf("Please enter your string of choice: \n");
	scanf("%s", testString);
	//char testString[]= "This is a string";
	printf("Here is your string: %s\n", testString);
	int convertInt = (atoi(testString));

	printf("Converted into an integer, your string is: %d\n", convertInt);


	return (0);
}
