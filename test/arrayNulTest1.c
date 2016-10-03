#include <stdio.h>
int main(int argc, char *argv[]) {

	char *testArray = { "benjamin" };
	printf("%d\n", sizeof(testArray));
	printf("%s\n", testArray);

	//testArray[8] = "\0";
	printf("%c\n", testArray[7]);
}
