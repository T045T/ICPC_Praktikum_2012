#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 256; i++) {
		cout << endl;
		int k = i;
		for (int j = 1; j < 8; j++) {
			cout << j << ((k % 2) ? "-" : "/");
			k >>= 1;
		}
		cout << "8" << endl;
	}
}