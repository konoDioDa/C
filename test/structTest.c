#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct pokemon {

	char *name;
	char *type1;
	char *type2;
	int number;
	int weight;
};

struct pokemon *addToPokedex(char *name, char *type1, char *type2, int number, float weight) {

	struct pokemon *mon = malloc(sizeof(struct pokemon));
	assert(mon != NULL);

	mon->name = strdup(name);
	mon->type1 = strdup(type1);
	mon->type2 = strdup(type2);
	mon->number = number;
	mon->weight = weight;

	return mon;
}

void printPokemon(struct pokemon *mon) { 

	printf("\nLet's learn about %s! \n", mon->name);
	//printf("Name: %s \n", mon->name);
	printf("\t # %d \n", mon->number);
	printf("\t Weight: %f Lbs. \n", mon->weight);
	printf("\t Type 1: %s \n", mon->type1);
	printf("\t Type 2: %s \n", mon->type2);
}

int main(int argc, char *argv[]) {

	struct pokemon *jigglypuff = addToPokedex("Jigglypuff", "Normal", "Fairy", 39, 12.4);
	struct pokemon *gothitelle = addToPokedex("Gothitelle", "Phychic", "none", 576, 97);

	printPokemon(jigglypuff);
}
