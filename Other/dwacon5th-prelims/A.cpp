#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<double> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  double mk = accumulate(a.begin(), a.end(), 0) / (double)n;
  vector<double> diff(n);
  for(int i = 0; i < n; i++){
    diff[i] = abs(a[i] - mk);
  }
  cout << find(diff.begin(), diff.end(), *min_element(diff.begin(), diff.end())) - diff.begin() << endl;
}