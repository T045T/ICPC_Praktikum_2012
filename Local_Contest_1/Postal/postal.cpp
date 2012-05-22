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
		vector<pair<double, double> > houseVec;
		for (int i = 0; i < houses; i++) {
			pair<double, double> input;
			cin >> input.first;
			cin >> input.second;
			houseVec.push_back(input);
		}
		sort (houseVec.begin(), houseVec.begin() + houseVec.size());
		count = 0;
		for (int i = 0; i < houseVec.size(); i++) {
			for (int j = i+1; j < houseVec.size(); j++) {
				if (   (int) houseVec[i].first  < (int) houseVec[j].first
					&& (int) houseVec[i].second < (int) houseVec[j].second) {
					sum += houseVec[j].first - houseVec[i].first;
					sum += houseVec[j].second - houseVec[i].second;
					count++;
				}
			}
		}
		sum /= (double) count;
		printf("%.8f\n", sum);
	}
}
