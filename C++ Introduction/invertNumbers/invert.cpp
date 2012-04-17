#include <iostream>

using namespace std;

const int max_n = 1000;
int array[max_n];

int main () {
	int n = 0;
	while(cin >> array[n++]);
	n--;
	
	cout << "Es gibt " << n-- << " Zahlen" << endl;
	while(n >= 0) cout << array[n--] << " ";
	cout << endl;
}
