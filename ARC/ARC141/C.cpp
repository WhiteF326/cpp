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


bool bracket_check(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(') st.push(c);
        else{
            if(st.empty()){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    n *= 2;
    vector<int> p(n), q(n);
    aryin(p, n);
    for(int &v : p) v--;
    aryin(q, n);
    for(int &v : q) v--;

    {
        bool flg = true;
        for(int i = 0; i < n; i++){
            if(p[i] != i) flg = false;
        }
        if(flg){
            //
        }
    }

    vector<int> q_pos(n, 0);
    for(int i = 0; i < n; i++){
        q_pos[q[i]] = i;
    }

    vector<char> ans(n);

    int mx = -1, mn = INT_MAX, cur = 0;
    int sum = 0;
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < 2; j++){
            chmax(mx, q_pos[p[i * 2 + j]]);
            chmin(mn, q_pos[p[i * 2 + j]]);
        }
        cur += 2;
        if(mn % 2 == 0 && mx - mn + 1 == cur){
            int start = i * 2 - cur + 2;
            for(int j = 0; j < cur / 2; j++){
                ans[p[j + start]] = '(';
            }
            for(int j = cur / 2; j < cur; j++){
                ans[p[j + start]] = ')';
            }
            mx = -1, mn = INT_MAX, cur = 0;
        }
    }
    
    string res = "";
    for(int i = 0; i < n; i++) res += ans[q[i]];
    print(res);

    if(bracket_check(res)){
        for(char c : ans) cout << c;
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}
