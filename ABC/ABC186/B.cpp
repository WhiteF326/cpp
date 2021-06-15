#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  vector<int> a(h * w, 0);
  for(int i = 0; i < h * w; i++) cin >> a[i];
  cout << accumulate(a.begin(), a.end(), 0) - (*min_element(a.begin(), a.end()) * h * w) << endl;
}