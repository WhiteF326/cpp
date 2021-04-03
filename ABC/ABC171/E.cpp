#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> val(n);
	for(int i = 0; i < n; i++) cin >> val[i];
	int allx = 0;
	for(int i = 0; i < n; i++) allx = allx ^ val[i];
	for(int i = 0; i < n; i++){
		cout << (allx ^ val[i]);
		if(i != n - 1) cout << " ";
	}
	cout << endl;
}