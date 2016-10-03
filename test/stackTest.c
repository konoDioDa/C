#include <stdio.h>

typedef struct testStruct{

	int i1;
	int i2;
	float f1;
} C;
int main(int argc, char *argv[]) {

	struct testStruct ass;
	ass.i1 = 3;
	printf("Struct i1: %d\n", ass.i1);



	int structSize = (sizeof(struct testStruct));
	printf("The size of [testStruct] is: %d\n", structSize);
//	ass->i1 = 3;
//	int 
//	printf("My first integer is: %d\n", ass->i1);
}
