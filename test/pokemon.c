#include <stdio.h>

int main(int argc, char *argv[]) {

	int prime[] = { 1, 3, 5, 7, 11, 13, 17};
	char *pokemon[] = { "Slowpoke", "Jigglypuff", "Bulbasaur", "Gothorita" };
	
	int pokeSize = sizeof(pokemon) / sizeof(int);
	printf("%d \n", pokeSize);
	int count = 3;
	int i = 0;
	for( i = 0; i < count + 1; i++ ) {
		printf("Who's that Pokemon?!\n");
		printf("It's %s!\n", pokemon[i]);
	} 
	printf("My favorite Pokemon is %s!\n", pokemon[3] );

	char **pikaman = pokemon;
	printf("My favorite pikamans is %s! \n", pikaman[3]);
}
