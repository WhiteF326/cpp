#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint1000000007
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	int n = int(s.length());
	int k; cin >> k;
	
	// dp[i][j] = 末尾の元の文字が i で、全て j に揃える場合の最小 flip 回数
	vector<vector<int>> dp(2, vector<int>(2, 0));
	for(int i = 0; i <= 1; i++) dp[s[i] - '0'][i] = (s[i] - 0 == i);
	for(int i = 1; i < n; i++){
		vector<vector<int>> ndp(2, vector<int>(2, 0));
		if(s[i] == '1'){
			ndp[1][0] += dp[0][0];
			ndp[0][0] += dp[0][0];
			ndp[1][1] += dp[0][1];
			ndp[0][1] += dp[0][1];
		}
		if(s[i] == '0'){
			ndp[1][0] += dp[1][0];
			ndp[0][0] += dp[1][0];
			ndp[1][1] += dp[1][1];
			ndp[0][1] += dp[1][1];
		}
	}
}