#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct node {
	node* children[2];
	bool end;
	bool subnet;
	node (bool end, bool subnet) : end(end), subnet(subnet) { children[0] = 0; children[1] = 0;};
};

int main () {
	string input;

	node* root = new node(false, false);
	node* currentNode;

	getline(cin, input);
	istringstream is(input);
	int ips;
	is >> ips;
	for (int i = 0; i < ips; i++) {
		getline(cin, input);
		currentNode = root;
		for (int j = 0; j < input.size(); j++) {
			int value = ((char) input[j]) - '0';
			if (currentNode->children[value] == 0) {
				for (int k = j; k < input.size() - 1; k++) {
					value = ((char) input[j]) - '0';
					currentNode->children[value] = new node(false, (input[k + 1] == '*'));
					currentNode = currentNode->children[value];
				}
				if (input[input.size() - 1] != '*') {
					value = ((char) input[j]) - '0';
					currentNode->children[value] = new node(true, (input[input.size()] == '*'));
					currentNode = currentNode->children[value];
				}
			} else {
				currentNode = currentNode->children[value];
			}
		}
	}
	getline(cin, input);
	istringstream iss(input);
	int testIPs;
	iss >> testIPs;
	for (int i = 0; i < testIPs; i++) {
		getline(cin, input);
		bool match = false;
		int j = 0;
		currentNode = root;
		while (!match && j < input.size()) {
			int value = ((char) input[j]) - '0';
			if (currentNode->children[value] == 0) {
				cout << "encountered missing node at " << (currentNode->subnet ? "subnet node " : "") << j << endl;
				if (currentNode->subnet) {
					match = true;
				} else {
					break;
				}
			} else {
				currentNode = currentNode->children[value];
				cout << "current node is " << (currentNode->subnet ? "subnet node and " : "") << (currentNode->end ? "end node." : "") << endl;
				if (currentNode->subnet || ((j == input.size() - 1) && currentNode->end)) {
					match = true;
					break;
				}
				j++;
			}
		}
		int value = ((char) input[j]) - '0';			
		if (!match && (j = input.size() - 1) && currentNode->children[value] != 0 && currentNode->children[value]->end) match = true;
		cout << (match ? "Yes" : "No") << endl;
	}
}
