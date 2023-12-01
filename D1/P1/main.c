#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


int main() {
	int total = 0;
	FILE* inputFile;
	char currentInput[127];

	inputFile = fopen("input.txt", "r");

	while(!feof(inputFile)) {
		fgets(currentInput, 127, inputFile);
		bool firstNumFound = false;
		char firstNum = 0;
		char currentNum = 0;
		for(char pos = 0; pos < 127; pos++) {
			if(currentInput[pos] == 0) {
				break;
			}
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
		printf("%i\n", (firstNum*10) + currentNum);
	}
	fclose(inputFile);
	printf("%i\n", total);
	return 0;
}
