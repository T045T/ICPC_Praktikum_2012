#include <vector>
#include <iostream>

using namespace std;

int main() {
	int cases, dwarves, min, minIndex, swaps;
	cin >> cases;
	while (cases > 0) {
		cin >> dwarves;
		swaps = 0;
		vector<int> dwarfVector = vector<int>(dwarves);
		for (int i = 0; i < dwarves; i++) {
			cin >> dwarfVector[i];
		}
		for (int i = 0; i < dwarves; i++) {
			min = dwarfVector[i];
			minIndex = i;
			for (int j = i+1;  j < dwarves; j++) {
				if (dwarfVector[j] < min) {
					min = dwarfVector[j];
					minIndex = j;
				}
			}
			if (minIndex != i) {
				swaps++;
				dwarfVector[minIndex] = dwarfVector[i];
				dwarfVector[i] = min;
				while (i+1 < dwarves && dwarfVector[i+1] - dwarfVector[i] <= 1) i++;
			}
		}
		cout << swaps << endl;
		cases--;
	}
}
