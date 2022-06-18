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


ll binom(int n, int k){
    ll ans = 1;
    for(int i = 0; i < k; i++){
        ans *= n - i;
    }
    for(int i = 0; i < k; i++){
        ans /= i + 1;
    }
    return ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);

    ll ans = binom(n, 3);

    // 全部 - (2 つが一致) * 3 - (3 つが一致)
    vector<int> ctr(200001, 0);
    for(int v : a) ctr[v]++;

    for(int i = 1; i <= 200000; i++){
        if(ctr[i] < 2) continue;
        // 2 個選ぶところの組み合わせ + 残りの選び方
        ans -= binom(ctr[i], 2) * (n - ctr[i]);
        if(ctr[i] < 3) continue;
        ans -= binom(ctr[i], 3);
    }

    cout << ans << endl;
}
