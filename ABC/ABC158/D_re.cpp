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
    deque<char> d;
    for(char c : s) d.push_back(c);

    int turn = 0;

    int q; cin >> q;
    query(q){
        int t; cin >> t;
        if(t == 1){
            turn ^= 1;
        }else{
            int f; cin >> f;
            char c; cin >> c;
            if((f + turn) & 1){
                d.push_front(c);
            }else{
                d.push_back(c);
            }
        }
    }

    while(d.size()){
        if(turn){
            cout << d.back();
            d.pop_back();
        }else{
            cout << d.front();
            d.pop_front();
        }
    }cout << endl;
}