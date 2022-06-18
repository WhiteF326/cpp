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
    
    ll n; cin >> n;
    ll x, m; cin >> x >> m;
    ll f = x;

    ll ans = 0;
    vector<int> fd(m, -1);
    for(int i = 0; i < m + 1; i++){
        if(fd[x] != -1){
            // サイクルの検出
            int st = fd[x], rl = i - fd[x];
            vector<int> vl;
            vl.reserve(m);
            for(int j = 0; j < rl; j++){
                vl.push_back(x);
                x = (x * x) % m;
            }
            ans += accumulate(all(vl), 0LL) * ((n - st) / rl - 1);
            for(int j = 0; j < (n - st) % rl; j++){
                ans += vl[j];
            }
            break;
        }else{
            fd[x] = i;
            ans += x;
            x = (x * x) % m;
        }
    }

    cout << ans << endl;
}
