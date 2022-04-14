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


namespace shiroha{
    namespace datastructure{
        template<typename T>
        class RangeSum2D{
        public:
            RangeSum2D(vector<vector<T>> &v){
                int h = v.size();
                int w = v[0].size();

                d.assign(h + 1, vector<T>(w + 1, T()));
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] = v[i][j];
                    }
                }
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] += d[i + 1][j];
                    }
                }
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] += d[i][j + 1];
                    }
                }
            };

            // get sum of [(l1, r1) : (l2 : r2))
            T get(int l1, int r1, int l2, int r2){
                return d[l2][r2] - d[l1][r2] - d[l2][r1] + d[l1][r1];
            }

        private:
            vector<vector<T>> d;
        };
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> d(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> d[i][j];

    shiroha::datastructure::RangeSum2D<int> rs(d);

    int q; cin >> q;
    query(q){
        int p; cin >> p;
        int ans = 0;
        for(int i = 1; i * i <= p; i++){
            int ver = i, hor = min(n, p / i);
            for(int t = 0; t < 2; t++){
                for(int x = 0; x <= n - ver; x++){
                    for(int y = 0; y <= n - hor; y++){
                        chmax(ans, rs.get(x, y, x + ver, y + hor));
                    }
                }
                swap(ver, hor);
            }
        }
        cout << ans << "\n";
    }
    fflush(stdout);
}