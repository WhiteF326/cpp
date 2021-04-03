#include <bits/stdc++.h>
using namespace std;

int main() {
	int c; cin >> c;
	vector<vector<int>> size(c, vector<int>(3));
	for(int i = 0; i < c; i++){
		for(int j = 0; j < 3; j++) cin >> size[i][j];
		sort(size[i].begin(), size[i].end());
	}
	int res = 1;
	for(int j = 0; j < 3; j++){
		vector<int> eachMax(c);
		for(int i = 0; i < c; i++){
			eachMax[i] = size[i][j];
		}
		res *= *max_element(eachMax.begin(), eachMax.end());
	}
	cout << res << endl;
}