#include <utility>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int houses, count;
	double sum;
	while (cin >> houses) {
		sum = 0.0;
		vector<vector<vector<pair<double, double> > > > map = 
			vector<vector<vector<pair<double, double> > > >(10, vector<vector<pair<double, double> > >(10));
		//vector<pair<double, double> > houseVec;
		for (int i = 0; i < houses; i++) {
			pair<double, double> input;
			cin >> input.first;
			cin >> input.second;
			map[(int) input.first][(int) input.second].push_back(input);
			//houseVec.push_back(input);
		}
		//sort (houseVec.begin(), houseVec.begin() + houseVec.size());
		count = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < map[i][j].size(); k++) {
					for(int inner_i = i; inner_i < 10; inner_i++) {
						for (int inner_j = j; inner_j < 10; inner_j++) {
							for (int inner_k = 0; inner_k < map[inner_i][inner_j].size(); inner_k++) {
								sum += map[inner_i][inner_j][inner_k].first - map[i][j][k].first;
								sum += map[inner_i][inner_j][inner_k].second - map[i][j][k].second;
							}
						}
					}
				}
			}
		}
		sum /= (double) count;
		printf("%.8f\n", sum);
	}
}
