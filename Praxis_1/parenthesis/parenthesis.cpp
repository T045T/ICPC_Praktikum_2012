#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

bool evaluate(istream& is) {
	char currentChar;
	
	stack<int> oldSquare;
	stack<int> oldRound;
	
	int round = 0;
	int square = 0;
	bool valid = true;
	
	while(is.get(currentChar)) {
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
	} // endline, space, tab
	valid &= (round == 0) && (square == 0);
	return valid;
}


int main () {
	string input;
	int testCases;
	getline(cin, input);
	istringstream iss(input);
	iss >> testCases;
	for (int i = 0; i < testCases; i++) {
		getline(cin, input);
		istringstream is(input);
		cout << (evaluate(is) ? "Yes" : "No") << endl;
	}
}
