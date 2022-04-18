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


const int infl = 1<<30;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    int ls = s.length(), lt = t.length();
    // dp[i][j] = sのi文字目を選ぶ場合にtがj文字目になる場合の部分列の長さ
    vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));
    dp[0][0] = 0;
    for(int i = ls - 1; i >= 0; i--){
        for(int j = lt - 1; j >= 0; j--){
            chmax(dp[i][j], max(dp[i + 1][j], dp[i][j + 1]));
            if(s[i] == t[j]){
                chmax(dp[i][j], dp[i + 1][j + 1] + 1);
            }
        }
    }

    queue<char> q;
    int l = 0, r = 0;
    while(l < ls && r < lt){
        if(s[l] == t[r]){
            q.push(s[l]);
            l++, r++;
        }else if(dp[l][r] == dp[l + 1][r]){
            l++;
        }else if(dp[l][r] == dp[l][r + 1]){
            r++;
        }
    }

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }cout << endl;
}
