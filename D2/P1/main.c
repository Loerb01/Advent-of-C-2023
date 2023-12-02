#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* inputFile;
	char currentInput[255];

	inputFile = fopen("input.txt", "r");

	int total = 0;

	for(int game = 1;; game++) {

		memset(currentInput, 0, 255);
		fgets(currentInput, 255, inputFile);
		if(feof(inputFile)) {
			break;
		}

		int maxBlue = 0;
		int	maxRed = 0;
		int maxGreen = 0;

		char* token = strtok(currentInput, ":,;\n");
		while(token != NULL) {
			token = strtok(NULL, ":,;\n");
		}

		char* currentStart = currentInput;
		while(true) {
			currentStart = strchr(currentStart, '\0')+1;
			int num = atoi(currentStart);
			char* end = strchr(currentStart, '\0');
			if(end == currentStart+1) {
				break;
			}

			switch(*(end-1)) {
				case 'n':
					if(maxGreen < num) {
						maxGreen = num;
					}
					break;
				case 'd':
					if(maxRed < num) {
						maxRed = num;
					}
					break;
				case 'e':
					if(maxBlue < num) {
						maxBlue = num;
					}
					break;
			}
		}

		printf("Game %i: MaxRed = %i, MaxBlue = %i, MaxGreen = %i\n", game, maxRed, maxBlue, maxGreen);

		if(maxBlue > 14 || maxGreen > 13 || maxRed > 12) {
			printf("Game %i invalid!\n", game);
			continue;
		}

		total += game;

	}

	fclose(inputFile);
	printf("Total: %i", total);

	return 0;
}
