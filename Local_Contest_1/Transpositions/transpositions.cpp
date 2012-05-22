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
		vector<int> positions = vector<int>(dwarves);
		for (int i = 0; i < dwarves; i++) {
			cin >> dwarfVector[i];
			dwarfVector[i]--;
			positions[dwarfVector[i]] = i;
		}
		for (int i = 0; i < dwarves; i++) {
			if (positions[i] != i) {
				swaps++;
				dwarfVector[positions[i]] = dwarfVector[i];
				dwarfVector[i] = i;
				positions[dwarfVector[positions[i]]] = positions[i];
				positions[i] = i;
			}
		}
		cout << swaps << endl;
		cases--;
	}
}
