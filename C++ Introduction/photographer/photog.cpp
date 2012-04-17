#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct data {
	float slope;
	int distance;
	string name;
};

bool comparePeople(const data &P1, const data &P2) {
	float diff = P1.slope - P2.slope;
	if (diff < 0.000001 && diff > -0.000001 ) {
		return P1.distance < P2.distance;
	} else {
		return diff > 0;
	}
}

int main() {
	vector<data> people;
	data person;
	string name;
	int x, y;
	while (cin >> name >> x >> y) {
		person.slope = y / (float) x;
		person.distance = x * x + y* y;
		person.name = name;
		people.push_back(person);
	}
	sort(people.begin(), people.end(), comparePeople);
	for (int i = 0; i < (int) people.size(); i++) {
		cout << people[i].name << endl;
	}
}
