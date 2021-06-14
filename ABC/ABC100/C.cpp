#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n; vector<int> s(n), a(n);
  int maxs = 0;
  for(int i = 0; i < n; i++){
    cin >> s[i]; maxs = max(maxs, s[i]);
  }
  for(int i = 0; i <= (int)log2(maxs + 1); i++){
    for(int j = 0; j < n; j++){
      if(s[j] % (int)pow(2, i) == 0 && s[j] >= pow(2, i)){a[j] = i;}
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) ans += a[i];
  cout << ans << endl;
}