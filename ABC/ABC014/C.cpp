#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> r(1000002, 0);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    r[a]++, r[b + 1]--;
  }
  vector<int> ans(1000001, 0);
  int pt = 0;
  for(int i = 0; i < 1000001; i++){
    pt += r[i];
    ans[i] = pt;
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
}