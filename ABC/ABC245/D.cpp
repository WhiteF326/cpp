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
    
    int n, m; cin >> n >> m;
    n += 1, m += 1;
    vector<int> a(n);
    aryin(a, n);
    reverse(all(a));

    vector<int> c(n + m - 1);
    aryin(c, n + m - 1);
    reverse(all(c));

    stack<int> st;
    for(int i = 0; i < m; i++){
        int rev = c[i] / a[0];
        st.push(rev);

        for(int j = 0; j < n; j++){
            c[i + j] -= a[j] * rev;
        }
    }

    for(int i = 0; i < m; i++){
        cout << st.top() << " ";
        st.pop();
    }cout << endl;
}
