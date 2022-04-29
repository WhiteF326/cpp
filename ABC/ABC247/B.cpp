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
    
    int n; cin >> n;
    vector<pair<string, string>> ns(n);
    for(int i = 0; i < n; i++) cin >> ns[i].first >> ns[i].second;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        mp[ns[i].first]++;
        mp[ns[i].second]++;
    }

    for(int i = 0; i < n; i++){
        bool ans = false;
        if(mp[ns[i].first] == 1) ans = true;
        if(mp[ns[i].second] == 1) ans = true;
        if(ns[i].first == ns[i].second) ans = true;
        if(!ans){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
