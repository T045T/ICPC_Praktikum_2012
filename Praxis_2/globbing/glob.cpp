#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int testCases;
	int starPos, plusPos, match;
	char wildcard;
	string input;
	string pattern;
	string firstPart, secondPart;
	string str;
	getline(cin, input);
	istringstream is(input);
	is >> testCases;
	for (int i = 0; i < testCases; i++) {
		getline (cin, pattern);
		getline (cin, str);
		plusPos = pattern.find('+');
		starPos = pattern.find('*');
		if (plusPos != string::npos) {
			firstPart = pattern.substr(0, plusPos);
			secondPart = pattern.substr(plusPos +1);
			wildcard = '+';
		} else if (starPos != string::npos) {
			firstPart = pattern.substr(0, starPos);
			secondPart = pattern.substr(starPos +1);
			wildcard = '*';
		} else { 
			firstPart = pattern;
			secondPart = "";
			wildcard = '0'; 
		}
		if (
			(wildcard == '*' && str.size() >= firstPart.size() + secondPart.size())
			|| (wildcard == '+' && str.size() >= firstPart.size() + secondPart.size() + 1)
			|| (wildcard == '0' && str.size() == firstPart.size())
			) {
			bool match = false;
			int i = 0;
			while (i < firstPart.size() && firstPart[i] == str[i]) i++;
			match = i == firstPart.size();
			i = 0;
			while (i < secondPart.size() && secondPart[secondPart.size() - (i + 1)] == str[str.size() - (i + 1)]) i++;
			match = match && (i == secondPart.size());
			cout << (match ? "Yes" : "No") << endl;
		} else {
			cout << "No" << endl;
		}
	}	
}
