#include <stdio.h>

int main(int argc, char *argv[]) {

	int i = 0;

	// go through each sting in argv
	// why am I skipping argv[0]?
	
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// let's make ou own array of strings
	char *states[] = { "California", "Oregon", "Washington", "Texas"};

	int num_states = 4;
	int test_number = 5;
	
	for (i = 0; i < num_states; i++, test_number++) {
		int fix_num = i;
		fix_num++;
		printf("state %d: %s\n", fix_num, states[i]);
	}
	
	return 0;
}
