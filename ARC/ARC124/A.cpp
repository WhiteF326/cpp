#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

constexpr ll modv = 998244353;

int main(){
  int n, k; cin >> n >> k;
  vector<ll> s(n, k);

  for(int i = 0; i < k; i++){
    string c; cin >> c;
    int p; cin >> p; p--;

    if(c == "L"){
      for(int j = 0; j < p; j++){
        if(s[j] != 1) s[j]--;
      }
      s[p] = 1;
    }else{
      for(int j = p + 1; j < n; j++){
        if(s[j] != 1) s[j]--;
      }
      s[p] = 1;
    }
  }
  ll ans = 1;
  for(int i = 0; i < n; i++){
    ans = (ans * s[i]) % modv;
  }
  cout << ans << endl;
}