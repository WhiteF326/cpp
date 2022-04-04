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


int n;
double dp[310][310][310];
double rev(int i, int j, int k){
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if(i > 0) res += rev(i - 1, j, k) * i;
    if(j > 0) res += rev(i + 1, j - 1, k) * j;
    if(k > 0) res += rev(i, j + 1, k - 1) * k;

    res += n;
    res *= 1.0 / (i + j + k);

    dp[i][j][k] = res;
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    vector<int> a(3, 0);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        a[v - 1]++;
    }

    memset(dp, -1, sizeof(dp));

    cout << fs(12) << rev(a[0], a[1], a[2]) << endl;
}
