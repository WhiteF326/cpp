#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	//全ての要素数と2個あった要素数それぞれ
	unordered_map<int, int> v;
	for(int i = 0; i < a; i++){
		int n; cin >> n;
		v[n]++;
	}
	for(int i = 0; i < b; i++){
		int n; cin >> n;
		v[n]++;
	}
	int u = v.size(), n = 0;
	for(auto itr = v.begin(); itr != v.end(); itr++){
		if(itr->second == 2) n++;
	}
	cout << fixed << setprecision(10) << (n / (double)u) << endl;
}