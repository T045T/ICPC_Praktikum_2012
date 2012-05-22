#include <utility>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct mapSquare {
	double value;
	int houses;
};

int main() {
	int houses, count;
	double sum;
	double tmp, tmp_i, tmp_j;
	while (cin >> houses) {
		sum = 0.0;
		mapSquare input;
		input.value = 0.0;
		input.houses = 0;
		vector<pair<double, double> > houseVec;
		vector<vector<mapSquare > > map = vector<vector<mapSquare> > (10, vector<mapSquare> (10, input));
		for (int i = 0; i < houses; i++) {
			cin >> tmp_i >> tmp_j;
			pair<double, double> input;
			input.first = tmp_i;
			input.second = tmp_j;
			houseVec.push_back(input);
			map[(int) tmp_i][(int) tmp_j].value += (tmp_i + tmp_j);
			map[(int) tmp_i][(int) tmp_j].houses++;
		}
		
		count = 0;
		for (int foo = 0; foo < houseVec.size(); foo++) {
			pair<double, double> house = houseVec[foo];
			for(int inner_i = (int) house.first+1; inner_i < 10; inner_i++) {
				for (int inner_j = (int) house.second+1; inner_j < 10; inner_j++) {
					if (map[inner_i][inner_j].houses > 0){
						tmp = house.first + house.second;
						sum += map[inner_i][inner_j].value - tmp;
						count+= map[inner_i][inner_j].houses;
					}
				}
			}
		}
		
		sum /= (double) count;
		printf("%.8f\n", sum);
	}
}
