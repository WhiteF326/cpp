#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x) 42;
#define printarray(x) 42;
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
    
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = INT_MAX;

    // i 個に分けてみる
    for(int i = n; i >= 1; i--){
        if(n % i) continue;
        int res = 0;
        int p = n / i;
        for(int j = 0; j < i; j++){
            vector<int> ctr(26, 0);
            for(int k = 0; k < p; k++){
                ctr[s[j + k * i] - 'a']++;
            }
            res += p - *max_element(all(ctr));
        }
        if(res <= k){
            chmin(ans, i);
        }
    }
    cout << ans << endl;
}
