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
    
    string s; cin >> s;
    bool large = false, small = false;
    map<char, bool> ext;

    for(char c : s){
        if(ext[c] == true){
            cout << "No" << endl;
            return 0;
        }else{
            ext[c] = true;
            if(c <= 'Z') large = true;
            else small = true;
        }
    }
    
    if(large && small){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
