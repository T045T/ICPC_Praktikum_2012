#include <vector>
#include <iostream>

using namespace std;

struct sptEntry {
	int value;
	bool valid;
};

int log2(int val) {
	int ret = -1;
	while (val != 0) {
		val >>= 1;
		ret++;
	}
	return ret;
}

int twoPow(int val) {
	return 1 << val;
}

int main() {
	// Read stuff
	
	int width, height;
	vector<vector<int> > map = vector<vector<int> >(width, vector<int>(height, 0));
	/*
	** Build lvl 1 sparse table
	*/
	
	//initialize
	int heightLog = log2(height);
	sptEntry prototype = {0, false};
	vector<vector<vector<sptEntry> > > verticalTables = vector<vector<vector<sptEntry> > > (width, vector<vector<sptEntry> >(height, vector<sptEntry>(heightLog, prototype)));
	for (int column = 0; column < width; column++) {
		for (int row = 0; row < height; row++) {
			for (int sptIndex = 0; sptIndex < heightLog; sptIndex++) {
				int indexPow = twoPow(sptIndex);
				if (indexPow + row < height) {
					for (int i = row; i < indexPow; i++) {
						if (!verticalTables[column][row][sptIndex].valid || map[column][row] > verticalTables[column][row][sptIndex].value) {
							verticalTables[column][row][sptIndex].value = map[column][row];
							verticalTables[column][row][sptIndex].valid = true;
						}
					}
				}
			}
		}
	}
}