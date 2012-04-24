#include <iostream>
#include <stack>
#include <string>

using namespace std;

void evaluate();

int main() {
	stack<char> numbers;
	stack<char> operators;
	
	int testCases;
	cin >> testCases;
	cin.ignore();
	
	for (int i = 0; i < testCases; i++) {
		evaluate();
	}
	return 0;
}

void evaluate() {
	stack<char> numbers;
	stack<char> operators;
	char c;
	int state = 0; // 0: start, 1 -> add / sub, 2 -> mul / div
	do {
		cin.get(c);
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
				evaluate();
			break;
			case')':
			break;
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
	} while (c != 10 && c != ')');
	while (operators.size() > 0) {
		cout << operators.top();
		operators.pop();
	}
	cout << endl << endl	;
}