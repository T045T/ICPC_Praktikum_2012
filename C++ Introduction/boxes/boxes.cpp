#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<string> > boxes(1000);

int main() {
	int pos;
	string name;
	while ( cin >> pos >> name ) {
		boxes[pos].push_back(name);
	}
	for (int i = 0; i < 1000; i++) {
		for(int j=0; j < (int) boxes[i].size(); ++j) {
			cout << boxes[i][j] << endl;
		}
	}
}
