#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  int ans = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  if(n == 1){
    cout << (a[0] % 2 ? "first" : "second") << endl;
    return 0;
  }

  sort(all(a));
  int before = 0;
  for(int i = 0; i < n; i++){
    ans ^= ((a[i] - before) % 2) * (n - i - 1);
    before = a[i];
  }
  cout << (ans ? "first" : "second") << endl;
}