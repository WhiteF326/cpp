#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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


namespace shiroha {
    namespace datastructure {
        template<typename T>
        class SparseTable {
        public:
            SparseTable(const vector< T > &v) {
                int b = 0;
                while((1 << b) <= v.size()) ++b;
                st.assign(b, vector< T >(1 << b));
                for(int i = 0; i < v.size(); i++) {
                    st[0][i] = v[i];
                }
                for(int i = 1; i < b; i++) {
                    for(int j = 0; j + (1 << i) <= (1 << b); j++) {
                        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                    }
                }
                lookup.resize(v.size() + 1);
                for(int i = 2; i < lookup.size(); i++) {
                    lookup[i] = lookup[i >> 1] + 1;
                }
            }

            inline T prod(int l, int r) {
                int b = lookup[r - l];
                return min(st[b][l], st[b][r - (1 << b)]);
            }
        private:
            vector<vector<T>> st;
            vector<int> lookup;
        };
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    aryin(a, n);

    shiroha::datastructure::SparseTable<int> sp(a);
    query(q){
        int l, r; cin >> l >> r;
        cout << sp.prod(l, r) << "\n";
    }
    fflush(stdout);
}