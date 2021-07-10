#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

constexpr ll modv = 1000000007;

int main(){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> ac(n, 0);

  for(int i = 0; i < n - 1; i++){
    if(s[i] == 'A' && s[i + 1] == 'C'){
      ac[i + 1] = 1;
      i++;
    }
  }
  // 累積化
  for(int i = 0; i < n - 1; i++) ac[i + 1] += ac[i];

  // クエリ処理
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    l--, r--;
    cout << ac[r] - ac[l] << endl;
  }
}