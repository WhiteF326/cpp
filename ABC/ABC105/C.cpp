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

    stack<int> st;
    ll n; cin >> n;

    if(!n){
        cout << 0 << endl;
        return 0;
    }

    ll d = 1;
    while(n){
        st.push(n & 1);
        n -= (n & 1) * d;
        d *= -1;
        n >>= 1;
    }
    while(st.size()){
        cout << st.top();
        st.pop();
    }cout << endl;
}
