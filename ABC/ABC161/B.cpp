#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int sum = accumulate(a.begin(), a.end(), 0);
  int d = 0;
  for(int i = 0; i < n; i++){
    if(a[i] * 4 * m >= sum) d++;
  }
  cout << (d >= m ? "Yes" : "No") << endl;
}