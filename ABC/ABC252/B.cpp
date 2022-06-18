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
    vector<int> a(n);
    aryin(a, n);
    int x = *max_element(all(a));

    set<int> s;
    for(int i = 0; i < k; i++){
        int b; cin >> b;
        s.insert(b - 1);
    }

    for(int i = 0; i < n; i++){
        if(a[i] == x && s.find(i) != s.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
