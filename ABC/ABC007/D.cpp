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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b; cin >> a >> b;
    a--;
    
    auto fdp = [](string s){
        int n = s.length();
        vector<int> digits(n);
        for(int i = 0; i < n; i++) digits[i] = s[i] - '0';

        // dp[i][j][k][lost] = i 桁目が k である / largest = j / 使えない = lost
        ll dp[n + 1][2][10][2] = {0};
        dp[0][1][0][0] = 1;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev <= 9; prev++){
                for(int lost = 0; lost < 2; lost++){
                    // largest -> largest
                    dp[i + 1][1][digits[i]][(digits[i] % 5 == 4) | lost] += dp[i][1][prev][lost];
                    // largest -> not largest
                    for(int next = 0; next < digits[i]; next++){
                        dp[i + 1][0][next][(next % 5 == 4) | lost] += dp[i][1][prev][lost];
                    }
                    // not largest -> not largest
                    for(int next = 0; next <= 9; next++){
                        dp[i + 1][0][next][(next % 5 == 4) | lost] += dp[i][0][prev][lost];
                    }
                }
            }
        }

        ll res = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j <= 9; j++){
                res += dp[n][i][j][1];
            }
        }

        return res;
    };
    
    cout << fdp(to_string(b)) - fdp(to_string(a)) << endl;
}
