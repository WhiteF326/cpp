#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s; cin >> s;
	int t; cin >> t;

	int x = 0, y = 0;
	int f = 0;

	for(char c : s){
		if(c == 'L'){
			x--;
		}else if(c == 'R'){
			x++;
		}else if(c == 'U'){
			y++;
		}else if(c == 'D'){
			y--;
		}else{
			// ?
			f++;
		}
	}

	if(t == 1){
		cout << abs(x) + abs(y) + f << endl;
	}else{
		cout << max(abs(x) + abs(y) - f, int(s.length() % 2)) << endl;
	}
}
