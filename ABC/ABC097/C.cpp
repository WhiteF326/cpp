#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  string s; cin >> s;
  int k; cin >> k;

  int n = s.size();
  set<string> srt;

  for(int i = 0; i < n; i++){
    for(int j = 1; j <= 5; j++){
      srt.insert(s.substr(i, j));
    }
  }
  auto x = srt.begin();
  for(int i = 0; i < k - 1; i++) x++;

  cout << *x << endl;
}