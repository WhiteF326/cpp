#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> l(n);
  for(int i = 0; i < n; i++) cin >> l[i];

  sort(l.begin(), l.end());

  vector<ll> st(2001, 0);
  for(int i = 0; i < n; i++) st[l[i]]++;
  for(int i = 1; i <= 2000; i++) st[i] += st[i - 1];

  // a, bを full search
  ll ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      int mi = max(l[i] - l[j], l[j] - l[i]);
      int ma = l[i] + l[j];
      
      ll res = 0;
      if(1 <= ma) res += st[ma - 1];
      res -= st[mi];

      if(mi < l[i] && l[i] < ma) res--;
      if(mi < l[j] && l[j] < ma) res--;
      ans += res;
    }
  }
  cout << ans / 6 << endl;
}