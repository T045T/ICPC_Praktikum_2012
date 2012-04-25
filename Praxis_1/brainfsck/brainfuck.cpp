#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char tape[32768];
char program[128000];

int main () {
	int cases;
	int pointer;
	int bracketCount;
	int arrPointer;
	char currentChar;
	string input;
	getline(cin, input);
	istringstream is(input);
	is >> cases;
	for (int i = 0; i < cases; i++) {
		cout << "PROGRAM #" << i+1 << ":" << endl;
		vector<char> program(128000);
		vector<char> tape(32768);
		arrPointer = 0;
		bracketCount = 0;
		pointer = 0;
		while(true) {
			getline(cin, input);
			if(input == "end") break;
			istringstream checkStream(input);
			while (checkStream.get(currentChar) && arrPointer <128000) {
				if (currentChar == '%') {
					break;
				} else if (currentChar == '[') {
					bracketCount++;
				} else if (currentChar == ']') {
					bracketCount--;
				}
				if (currentChar != ' ') program[arrPointer++] = currentChar;
			}
		}
		if (bracketCount != 0) {
			cout << "COMPILE ERROR" << endl;
			continue;
		}
		//start interpretation;
		int programSize = arrPointer;
		bool seekForward = false;
		bool seekReverse = false;
		bracketCount = 0;
		arrPointer = 0;
		while (arrPointer < programSize) {
			switch (program[arrPointer]) {
				case '>':
					(pointer == 32767) ? (pointer = 0) :pointer++;
					arrPointer++;
				break;
				case '<':
					(pointer == 0) ? (pointer = 32767) : pointer--;
					arrPointer++;
				break;
				case '+':
					tape[pointer]++;
					arrPointer++;
				break;
				case '-':
					tape[pointer]--;
					arrPointer++;
				break;
				case '.':
					cout << tape[pointer];
					arrPointer++;
				break;
				case '[':
					if (tape[pointer] == 0) {
						bracketCount++;
						arrPointer++;
						while (arrPointer < programSize) {
							if (program[arrPointer] == '[') {
								bracketCount++;
							} else if (program[arrPointer] == ']') {
								bracketCount--;
							}
							arrPointer++;
							if (bracketCount == 0) break;
						}
					} else {
						arrPointer++;
					}
				break;
				case ']':
					if (tape[pointer] != 0) {
						bracketCount--;
						arrPointer--;
						while (arrPointer >0) {
							if (program[arrPointer] == '[') {
								bracketCount++;
							} else if (program[arrPointer] == ']') {
								bracketCount--;
							}
							if (bracketCount == 0) break;
							arrPointer--;
						}
					} else {
						arrPointer++;
					}
				break;
			}
		}
		cout << endl;
	}
}
