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
    vector<string> st;

    int ct = 0, ft = 0;
    for(int i = 0; i < s.length(); i++){
        if('A' <= s[i] && s[i] <= 'Z') ct++;
        if(ct == 2){
            ct = 0;
            st.push_back(s.substr(ft, i - ft + 1));
            ft = i + 1;
        }
    }

    sort(all(st), [](const string& a, const string& b){
        string t = a;
        t[0] = tolower(t[0]);
        t[a.length() - 1] = tolower(t[a.length() - 1]);
        string u = b;
        u[0] = tolower(u[0]);
        u[b.length() - 1] = tolower(u[b.length() - 1]);
        return t < u;
    });

    for(string t : st) cout << t;
    cout << endl;
}
