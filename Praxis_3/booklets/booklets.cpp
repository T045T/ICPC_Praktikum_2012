#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct entry{
	unsigned int value;
	int index;
};

bool sortByValue (const entry& i,const entry& j) { return (i.value < j.value); }
bool sortByIndex (const entry& i,const entry& j) { return (i.index < j.index); }

int main () {
	int schools, mySchool, activities, mySchoolStart;
	
	while (cin >> schools) {
		cin >> mySchool >> activities;
		vector<entry> activityValues = vector<entry>(activities);
		int div, mod;
		div = activities / schools;
		mod = activities % schools;
		mySchoolStart = 0;
		for (int i = 0; i < mySchool; i++) {
			mySchoolStart += (div + (i < mod ? 1 : 0));
		}
		for (int i = 0; i < activities; i++) {
			cin >> activityValues[i].value;
			activityValues[i].index = i;
		}
		sort (activityValues.begin(), activityValues.begin() + activityValues.size(), sortByValue);
		sort (activityValues.begin() + mySchoolStart, activityValues.begin() + mySchoolStart + div + (mySchool < mod ? 1 : 0), sortByIndex);
		cout << activityValues[mySchoolStart].value << endl;
	}
}