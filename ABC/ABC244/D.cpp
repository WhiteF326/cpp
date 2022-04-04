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
    
    string s = "   ", t = "   ";
    aryin(s, 3);
    aryin(t, 3);

    set<string> st;
    pair<int, int> swps[3] = {{0, 1}, {1, 2}, {0, 2}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            string u = s.c_str();
            swap(u[swps[i].first], u[swps[i].second]);
            swap(u[swps[j].first], u[swps[j].second]);
            st.insert(u);
        }
    }

    if(st.find(t) == st.end()){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
