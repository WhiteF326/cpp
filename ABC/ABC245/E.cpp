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


struct Square{
    int type;
    int height;
    int width;
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m), h, w;
    vector<Square> lp(n + m);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        a[i] = v;
        h.push_back(v);
    }
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        b[i] = v;
        w.push_back(v);
    }
    for(int i = 0; i < m; i++){
        int v; cin >> v;
        c[i] = v;
        h.push_back(v);
    }
    for(int i = 0; i < m; i++){
        int v; cin >> v;
        d[i] = v;
        w.push_back(v);
    }

    for(int i = 0; i < n; i++){
        lp[i] = {0, a[i], b[i]};
    }
    for(int i = 0; i < m; i++){
        lp[i + n] = {1, c[i], d[i]};
    }

    sort(all(lp), [](const Square& l, const Square& r){
        if(l.height == r.height){
            if(l.width == r.width){
                return l.type > r.type;
            }else{
                return l.width > r.width;
            }
        }else{
            return l.height > r.height;
        }
    });

    multiset<int> st;

    for(int i = 0; i < n + m; i++){
        if(lp[i].type == 0){
            if(st.lower_bound(lp[i].width) == st.end()){
                cout << "No" << endl;
                return 0;
            }else{
                st.erase(st.lower_bound(lp[i].width));
            }
        }else{
            st.insert(lp[i].width);
        }
    }

    cout << "Yes" << endl;
}
