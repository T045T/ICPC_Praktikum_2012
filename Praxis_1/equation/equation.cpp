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
	char c;
	
	for (int i = 0; i < testCases; i++) {
		evaluate();
	}
	return 0;
}

void evaluate() {
	stack<char> numbers;
	stack<char> operators;
	do {
		cin.get(c);
		cout << "Read ";
		switch(c) {
			case '*':
			cout << "a Multiplication ";
			break;
			case '/':
			cout << "a Division ";
			break;
			case '+':
			cout << "an Addition ";
			break;
			case '-':
			cout << "a Subtraction ";
			break;
			case '(':
			evaluate();
			cout << " Parenthesis ";
			break;
			case')':
			cout << " Parenthesis ";
			break;
			case 10: // newline
			
			break;
			default: // numbers
			cout << c + 0 << " ";
			break;
		}
		cout << "operator." << endl;
	} while (c != 10 && c != ')');
}