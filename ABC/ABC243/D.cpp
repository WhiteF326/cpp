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
    
    ll n, x; cin >> n >> x;
    string s; cin >> s;
    deque<int> q;
    while(x){
        q.push_front(x & 1);
        x >>= 1;
    }
    for(char c : s){
        if(c == 'U'){
            q.pop_back();
        }
        if(c == 'L'){
            q.push_back(0);
        }
        if(c == 'R'){
            q.push_back(1);
        }
    }

    ll ans = 0, cur = 1;
    while(q.size()){
        ans += cur * q.back();
        q.pop_back();
        cur <<= 1;
    }
    cout << ans << endl;
}
