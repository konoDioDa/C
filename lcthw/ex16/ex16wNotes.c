#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
// previous four lines, brings in additional headers, natch. notes found in ex16Desc

struct Person {
// defines struct [Person]
	char *name;
	int age;
	int height;
	int weight;
// previous four lines, defines an array [name] and integers age, height and weight. The // whole struct is a structure with four elements describing a person. Similar to a whole row in a
// database.
};

struct Person *Person_create(char *name, int age, int height, int weight) {
// defines fuction to create a struct of the type [Person]

	struct Person *who = malloc(sizeof(struct Person));
// asks OS for a block of memory via malloc,  matching the total size of the struct [Person]

	assert(who != NULL);

// tests to make sure that who is an appropriately sized block of memory. NULL is an unset or
// invalid pointer
	
	who->name = strdup(name);
// [strdup] sets the string string/array [name] as the [name] value of the struct
	who->age = age;
	who->height = height;
	who->weight = weight;

// previous 4 lines, initializes each field of the struct, defining what part of the struct will be 
// set by what

	return who;	
// returns the block of memory [who], we asked the OS for earlier
}

void Person_destroy(struct Person *who) {
// defines a foil to [Person_create], [Person_destroy]

	assert(who != NULL);

// once again checks to make sure our [who] block of memory is appropriately sized

	free(who->name);
	free(who);
// previous 2 lines, macro [free()] dallocates the memory previously allocated by [malloc()].
// deallocates the [name] field of [who], then deallocates [who] as a whole
}

void Person_print(struct Person *who) {
// creates fuction [Person_print], which pulls in a struct [Person] to print out the struct's values

	printf("Name: %s \n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
// previous four lines, standard [printf()] statements, but calling elements of the struct to provide
// values for our format strings (%s, %d, etc..)
}

int main(int argc, char *argv[]) {
//finally our main function

	// make two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

// previous two lines, creates two [Person] structs, [*joe] and [*frank] and uses the function
// [Person_create] to assign values to the various elements of the struct

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);

// mostly familiar except for format string [%p]. This specifies the memory location of whatever
// variable you call

	Person_print(joe);

// calls function [Person_print] with [joe] to print out all the elements of struct [*joe] in a 
// nicely formatted manner

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);
// previous two lines, does the same for Frank as we did for Joe. Common courtesy, init?

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
