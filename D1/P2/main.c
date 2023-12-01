#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

//Lets count the amount of letters in words! Fuck strlen()
/*
3
------
-ONE-
-TWO-
-SIX-
------
4
------
-FOUR-
-FIVE-
-NINE-
-ZERO-
------
5
------
-THREE-
-SEVEN-
-EIGHT-
*/

int main() {
	int total = 0;
	FILE* inputFile;
	char currentInput[127];

	inputFile = fopen("input.txt", "r");

	//Once again, requires two terminating '\n's
	while(!feof(inputFile)) {
		fgets(currentInput, 127, inputFile);

		bool firstNumFound = false;
		char firstNum = 0;
		char currentNum = 0;

		for(char pos = 0; pos < 127; pos++) {
			//Don't remember why I added the '\n', but here we are
			if(currentInput[pos] == 0 || currentInput[pos] == '\n') {
				break;
			}

			//There are way better ways to organize this, but this one made sense
			switch(currentInput[pos]) {//If the current char is a letter that might indicate a number:
				case 'o':
					//Slightly abusing the n part of strncmp
					if(strncmp(currentInput+pos, "one", 3) == 0) { // == 0 because ! might have been confusing to read
						//This block could probably be a function or compile time substitution
						if(!firstNumFound) {
							firstNum = 1;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 1;
					}
					break;

				case 't':
					if(strncmp(currentInput+pos, "two", 3) == 0) {
						if(!firstNumFound) {
							firstNum = 2;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 2;
					}else
					if(strncmp(currentInput+pos, "three", 5) == 0) {
						if(!firstNumFound) {
							firstNum = 3;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 3;
					}
					break;

				case 's':
					if(strncmp(currentInput+pos, "six", 3) == 0) {
						if(!firstNumFound) {
							firstNum = 6;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 6;
					}else
					if(strncmp(currentInput+pos, "seven", 5) == 0) {
						if(!firstNumFound) {
							firstNum = 7;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 7;
					}
					break;

				case 'f':
					if(strncmp(currentInput+pos, "four", 4) == 0) {
						if(!firstNumFound) {
							firstNum = 4;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 4;
					}else
					if(strncmp(currentInput+pos, "five", 4) == 0) {
						if(!firstNumFound) {
							firstNum = 5;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 5;
					}
					break;

				case 'n':
					if(strncmp(currentInput+pos, "nine", 4) == 0) {
						if(!firstNumFound) {
							firstNum = 9;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 9;
					}
					break;

				case 'e':
					if(strncmp(currentInput+pos, "eight", 5) == 0) {
						if(!firstNumFound) {
							firstNum = 8;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 8;
					}
					break;

				case 'z':
					if(strncmp(currentInput+pos, "zero", 4) == 0) {
						if(!firstNumFound) {
							firstNum = 0;
							firstNumFound = true;
							currentNum = firstNum;
							continue;
						}

						currentNum = 0;
					}

			}

			//Same as last problem from here on
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
