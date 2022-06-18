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

int n;
vector<int> p(200000);
vector<int> q(200000);

vector<int> posp(200000), posq(200000);

vector<int> lp(200000, -1), rp(200000, -1);
void dfs(int v){
    int ctr = posq[p[v]];
    if(v < n - 1){
        int l = posq[p[v + 1]];
        if(ctr > l){
            cout << p[v] << " left " << q[l] << endl;
            lp[p[v]] = q[l];
            dfs(v + 1);
        }
    }
    if(ctr > 0){
        int r = posq[p[posp[q[ctr - 1]] + 1]];
        if(ctr < r){
            cout << p[v] << " right " << q[r] << endl;
            rp[p[v]] = q[r];
            dfs(posp[q[r]]);
        }
    }else{
        int r = posq[p[posp[q[ctr]] + 1]];
        if(ctr < r){
            cout << p[v] << " right " << q[r] << endl;
            rp[p[v]] = q[r];
            dfs(posp[q[r]]);
        }
    }
}
void invalid(){
    cout << -1 << endl;
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    aryin(p, n);
    for(int &v : p) v--;
    aryin(q, n);
    for(int &v : q) v--;

    for(int i = 0; i < n; i++) posp[p[i]] = i;
    for(int i = 0; i < n; i++) posq[q[i]] = i;

    dfs(p[0]);

    for(int i = 0; i < n; i++){
        cout << lp[i] << " " << rp[i] << endl;
    }
}
