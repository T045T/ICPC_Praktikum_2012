#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int xSize, ySize, tmpValue;
	cin >> xSize >> ySize;
	
	int values[ySize][xSize];
	vector<int> tmpList;
	
	for (int y = 0; y < ySize; ++y) {
		for (int x = 0; x < xSize; ++x) {
			cin >> values[y][x];
		}
	}
	
	int xMin, yMin, xMax, yMax;
	while(cin >> xMin >> yMin >> xMax >> yMax) {
		xMin--;
		yMin--;
		xMax--;
		yMax--;

		for (int y = yMin; y <= yMax; ++y) {
			for (int x = xMin; x <= xMax; ++x) {
				tmpList.push_back(values[y][x]);
			}
		}
		cout << *min_element(tmpList.begin(), tmpList.end()) << endl;
		tmpList.clear();
	}
}
