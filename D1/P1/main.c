#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


int main() {
	int total = 0;
	FILE* inputFile;
	//Should be unsigned char
	char currentInput[127]; //assume no line longer the 127 characters

	inputFile = fopen("input.txt", "r");

	//input file needs 2 '\n's for this to work correctly
	while(!feof(inputFile)) {

		fgets(currentInput, 127, inputFile);
		bool firstNumFound = false;
		char firstNum = 0;
		char currentNum = 0;

		//This char should also be unsigned
		for(char pos = 0; pos < 127; pos++) {
			//Stop processing line at null termintator
			if(currentInput[pos] == 0) {
				break;
			}

			//Assembly got me fucked up
			if('0' <= currentInput[pos] && currentInput[pos] <= '9') {

				if(!firstNumFound) {
					firstNum = currentInput[pos] - '0';
					firstNumFound = true;
					currentNum = firstNum;
					continue;
				}

				currentNum = currentInput[pos] - '0';

			}

		}

		total += ((firstNum*10) + currentNum);
		printf("%i\n", (firstNum*10) + currentNum); //debug logging

	}

	fclose(inputFile);
	printf("%i\n", total);

	return 0;
}
