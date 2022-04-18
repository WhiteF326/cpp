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
    
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<pair<int, int>> sp(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        cin >> sp[i].first;
        sp[i].second = i;
    }

    sort(all(sp), greater<pair<int, int>>());

    int q; cin >> q;
    vector<int> v(q), w(q);
    vector<pair<int, int>> p(q);
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        cin >> v[i] >> w[i];
        v[i]--;
        p[i] = {w[i], i};
    }

    sort(all(p), greater<pair<int, int>>());

    int ptr = 0;
    dsu d(n);

    for(int i = 0; i < q; i++){
        int qno = p[i].second;
        while(ptr < m && sp[ptr].first > w[qno]){
            // cout << sp[ptr].second << endl;
            d.merge(a[sp[ptr].second], b[sp[ptr].second]);
            ptr++;
        }
        ans[qno] = d.size(v[qno]);
    }

    for(int v : ans) cout << v << "\n";

    fflush(stdout);
}
