#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct coin {
	bool canBeHeavy;
	bool canBeLight;
	bool touched;
};

int main() {
	int numCoins, trials, measurings, coinsMeasured;
	string result;
	
	coin temp = {true, true, false};
	
	string input;
	getline(cin, input);
	istringstream isss(input);
	isss >> trials;
	for (int trial = 0; trial < trials; trial++) {
		getline(cin, input);
		getline(cin, input);
		istringstream iss(input);
		iss >> numCoins >> measurings;
		
		vector<coin> coinMap = vector<coin>(numCoins, temp);
		
		for (int measuring = 0; measuring < measurings; measuring++) {
			// coinsMeasured describes the number of coins in the current weighing
			getline(cin, input);
			istringstream is(input);
			is >> coinsMeasured;
			vector<int> weighed = vector<int> (2 * coinsMeasured);
			for (int i = 0; i < 2 * coinsMeasured; i++) {
				is >> weighed[i];
				weighed[i]--;
			}
			getline(cin, input);
			switch(input[0]) {
				case '>':
					for (int i = 0; i < coinsMeasured; i++) {
						// cout << "Coin " << weighed[i] << " can't be light." << endl;
						coinMap[weighed[i]].canBeLight = false;
						coinMap[weighed[i]].touched = true;
					}
					for (int i = coinsMeasured; i < 2 * coinsMeasured; i++) {
						// cout << "Coin " << weighed[i] << " can't be heavy." << endl;
						coinMap[weighed[i]].canBeHeavy = false;
						coinMap[weighed[i]].touched = true;
					}
					for (int i = 0; i < numCoins; i++) {
						if (coinMap[i].touched) {
							coinMap[i].touched = false;
						} else {
							coinMap[i].canBeHeavy = false;
							coinMap[i].canBeLight = false;
						}
					}
				break;
				case '<':
					for (int i = 0; i < coinsMeasured; i++) {
						// cout << "Coin " << weighed[i] << " can't be heavy." << endl;
						coinMap[weighed[i]].canBeHeavy = false;
						coinMap[weighed[i]].touched = true;
					}
					for (int i = coinsMeasured; i < 2 * coinsMeasured; i++) {
						// cout << "Coin " << weighed[i] << " can't be light." << endl;
						coinMap[weighed[i]].canBeLight = false;
						coinMap[weighed[i]].touched = true;
					}
					for (int i = 0; i < numCoins; i++) {
						if (coinMap[i].touched) {
							coinMap[i].touched = false;
						} else {
							coinMap[i].canBeHeavy = false;
							coinMap[i].canBeLight = false;
						}
					}
				break;
				case '=':
					for (int i = 0; i < 2 * coinsMeasured; i++) {
						// cout << "Coin " << weighed[i] << " can't be light or heavy." << endl;
						coinMap[weighed[i]].canBeHeavy = false;
						coinMap[weighed[i]].canBeLight = false;
					}
				break;
				default:
					cout << "What the actual fuck?" << endl;
				break;
			}
		}
		int different = -1;
		for (int i = 0; i < numCoins; i++) {
			// cout << "Coin #" << i << ": " << (coinMap[i].canBeHeavy ? "H" : "") << (coinMap[i].canBeLight ? "L" : "") << endl;
			if (coinMap[i].canBeHeavy || coinMap[i].canBeLight) {
				different = (different == -1 ? i : -2);
			}
		}
		cout << (numCoins == 1 ?
			1
		: 
			( numCoins == 2 ?
				0
			:
				(different > -1 ?
					(different + 1)
				:
					0
				)
			)
		) << endl;
		if (trial != trials - 1) cout << endl;
	}
}