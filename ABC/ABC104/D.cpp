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

    string s; cin >> s;
    int n = int(s.length());
    vector<int> a, b, c, q;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') a.push_back(i);
        else if(s[i] == 'B') b.push_back(i);
        else if(s[i] == 'C') c.push_back(i);
        else q.push_back(i);
    }

    modint1000000007 ans = 0;
    for(int pos : b){
        int la = lower_bound(all(a), pos) - a.begin();
        int lc = c.end() - lower_bound(all(c), pos);
    }
    cout << ans.val() << endl;
}
