#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<bool> ans(n, false);
  for(int i = 0; i < k; i++){
    int d; cin >> d;
    for(int j = 0; j < d; j++){
      int a; cin >> a;
      ans[a - 1] = true;
    }
  }
  cout << n - accumulate(ans.begin(), ans.end(), 0) << endl;
}