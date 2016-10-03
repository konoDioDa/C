#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	long int usrInput;
	int pwrVector, inputLen;
	char *usrStrn;
	const char  *onesPlace[10] = {
			"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"},
					*tensPlace[9] = {
			"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninetey"},
					*pwrNames[3] = {
			"Thousand", "Million", "Billion"};
	ldiv_t usrDiv;


	printf("Please enter an integer... \n");
	scanf("%ld", &usrInput);

	inputLen = floor(log10(labs(usrInput))) + 1;
//inputLen helps me get pwrVector
	pwrVector = inputLen / 3;
//pwrVector allows me to iterate through thousand, million, billion 
	sprintf(usrStrn, "%ld", &usrInput);
//usrStrn[] will be what I use to print english number names
	usrDiv = ldiv(inputLen, 3);
//struct [inputDiv] via function [ldiv()] lets me get the quotient of [usrInput] divided by 3 
//with ([inputDiv.quot]) and the remainder with ([inputDiv.rem] probably not necessary here)
//REMEMBER BENJAMIN: [div()] works on integers, [ldiv()] is necessary for long integers

	printf("[inputLen] divided by 3 without remainder is equal to: %d\n", usrDiv.quot);
	
	int i;
	for(i = 0; i < inputLen; i++) {
		printf("Your power labels are: ");
		printf("%s", pwrNames[i]);

	}

	//usrQuot = inputDiv(usrInput, 3);
	/*for(i = 0; i < usrDiv.quot; i++) {
		printf("%s", pwrNames[i]);


	}*/



/*	printf("You entered %ld as your integer...\n", usrInput);
	printf("[pwrVector] is equal to: %d\n", pwrVector);

//getting count of numbers in [usrInput]. [abs()] returns the absolute value of it's input,
//log10 gets logarithm to base 10 of that value. [floor()] rounds down any potential  The final "+ 1" makes up for the fact that
//

	printf("The length of the user's input is: %d\n", inputLen);
	printf("The user's input as a string is %s...\n", usrStrn); */


//when printing the human readble thousand, million, etc..., do a for loop, but count down (i--) on pwrVector


	


	


}
