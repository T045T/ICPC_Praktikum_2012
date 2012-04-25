#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void evaluate(istream&);

int main() {
	
	int testCases;
	string input;
	getline(cin, input);
	istringstream iss(input);
	iss >> testCases;
	
	for (int i = 0; i < testCases; i++) {
		getline(cin, input);
		getline(cin, input);
		istringstream is(input);
		evaluate(is);
		cout << endl;
		if (i < testCases - 1) cout << endl;
	}
	return 0;
}

void evaluate(istream& is) {
	stack<char> operators;
	char c;
	int state = 0; // 0: start, 1 -> add / sub, 2 -> mul / div
	bool cont = true;
	while (cont) {
		cont = is.get(c);
		if (!cont) break;
		switch(c) {
			case '*':
			case '/':
				operators.push(c);
				state = 2;
			break;
			case '+':
			case '-':
				if (state == 1) {
					cout << operators.top();
					operators.pop();
				} else if (state == 2) {
					while (operators.size() > 0) {
						cout << operators.top();
						operators.pop();
					}
				}
				operators.push(c);
				state = 1;
			break;
			case '(':
				evaluate(is);
				if (operators.size() > 0 && state == 2) {
					cout << operators.top();
					operators.pop();
				}
			break;
			case ')':
				cont = false;
			case ' ':
			case 10: // newline	
			break;
			default: // numbers
				if (operators.size() > 0) {
					switch(state) {
						case 2:
							cout << c << operators.top();
							operators.pop();
							break;
						case 1:
						case 0:
							cout << c;
							break;
					}
				} else {
					cout << c;
				}
			break;
		}
	}
	while (operators.size() > 0) {
		cout << operators.top();
		operators.pop();
	}
}