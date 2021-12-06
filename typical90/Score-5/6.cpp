#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;

  vector<vector<int>> nx(n, vector<int>(26, INT_MAX));

  constexpr char a = 'a';
  for(int c = 0; c < n; c++){
    nx[c][s[c] - a] = c;
  }
  for(int c = 0; c < 26; c++){
    for(int i = n - 2; i >= 0; i--){
      if(nx[i][c] == INT_MAX) nx[i][c] = nx[i + 1][c];
    }
  }

  string ans = "";
  int ptr = 0;
  for(int i = 0; i < k; i++){
    for(int v = 0; v < 26; v++){
      if(nx[ptr][v] <= n + ans.length() - k){
        ans += (a + v);
        ptr = nx[ptr][v] + 1;
        break;
      }
    }
  }

  cout << ans << endl;
}