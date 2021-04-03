#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= min(i, 2); ++j) {
            string suffix = s.substr(i - j, j);
            for (int add = 1; add <= 2 && i + add <= n; ++add) {
                // 同じものが連続しないなら更新
                if (s.substr(i, add) != suffix) {
                    chmax(dp[i + add][add], dp[i][j] + 1);
                }
            }
        }
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
}