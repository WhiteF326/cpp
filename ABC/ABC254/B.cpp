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


struct pascalComb{
  vector<vector<ll>> f;
  int size;
  
  pascalComb(int size){
    this->size = size;

    f.resize(size + 5);
    for(int i = 0; i <= size; i++) f[i].resize(size + 5);
    f[0][0] = 1;
    for(int i = 1; i <= size; i++){
      f[i][0] = 1;
      for(int j = 1; j <= size; j++){
        f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
      }
    }
  }

  ll C(int n, int r){
    assert(n <= this->size);
    assert(r <= this->size);
    assert(r <= n);
    
    return f[n][r];
  }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;

    pascalComb c(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << c.C(i, j) << " ";
        }cout << endl;
    }
}
