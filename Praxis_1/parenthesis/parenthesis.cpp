#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool evaluate() {
	char currentChar;
	
	stack<int> oldSquare;
	stack<int> oldRound;
	
	int round = 0;
	int square = 0;
	bool valid = true;
	
	do {
		cin.get(currentChar);
		switch(currentChar) {
			case '(':
				round++;
				oldSquare.push(square);
				square = 0;
				break;
			case ')':
				valid &= square >= 0;
				valid &= --round >= 0;
				if (valid) {
					square = oldSquare.top();
					oldSquare.pop();
				} else {
					return valid;
				}
				break;
			case '[':
				square++;
				oldRound.push(round);
				round = 0;
				break;
			case ']':
				valid &= round >= 0;
				valid &= --square >= 0;
				if (valid) {
					round = oldRound.top();
					oldRound.pop();
				} else {
					return valid;
				}
				break;
			default:
				break;
		}
	} while (currentChar != 10 && currentChar != ' ' && currentChar != '\t'); // endline, space, tab
	return valid;
}


int main () {
	int testCases;
	cin >> testCases;
	cin.ignore();
	for (int i = 0; i < testCases; i++) {
		
		cout << (evaluate() ? "Yes" : "No") << endl;
	}
}
