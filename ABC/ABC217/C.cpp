#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> ans(n);

  for(int i = 0; i < n; i++){
    int p; cin >> p;
    ans[p - 1] = i + 1;
  }

  
}