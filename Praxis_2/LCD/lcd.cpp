#include <iostream>
#include <string>


using namespace std;

void printSegments(string digits, int size) {
	if (size == 0) return;
	for (int rows = 0; rows < size*2 + 3; rows++) {
		for (int foo = 0; foo < digits.size(); foo++) {
			int digit = digits[foo] - '0';
			if (rows == 0) {
				cout << " ";
				for (int i = 0; i < size; i++) cout << ((digit != 1 && digit != 4)? "-" : " ");
				cout << " ";
			} else if (rows == 1 + size) {
				cout << " ";
				for (int i = 0; i < size; i++) cout << ((digit != 0 && digit != 1 && digit != 7)? "-" : " ");
				cout << " ";
			} else if (rows == 2 + 2*size) {
				cout << " ";
				for (int i = 0; i < size; i++) cout << ((digit != 1 && digit != 4 && digit != 7)? "-" : " ");
				cout << " ";
			} else if (rows < size + 2) {
				if (digit != 1 && digit != 2 && digit != 3 && digit != 7) {
					cout << "|";
				} else {
					cout << " ";
				}
				for (int i = 0; i < size; i++) cout << " ";
				if (digit != 5 && digit != 6) {
					cout << "|";
				} else {
					cout << " ";
				}
			} else {
				if (digit != 1 && digit != 3 && digit != 4 && digit != 5 && digit != 7 && digit != 9) {
					cout << "|";
				} else {
					cout << " ";
				}
				for (int i = 0; i < size; i++) cout << " ";
				if (digit != 2) {
					cout << "|";
				} else {
					cout << " ";
				}
			}
			if (foo != digits.size() -1) cout << " ";
		}
		if (rows != size*2 + 2) cout << endl;
	}
	cout << endl << endl;
}

int main() {
	string num = "";
	int size = 1;
	while (num != "0" && size != 0) {
		cin >> size >> num;
		printSegments(num, size);
	}
}
