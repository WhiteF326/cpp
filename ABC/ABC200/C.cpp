#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> ext(200, 0);
 
  ll ans = 0;
  // 200で割った余りが同じ数字
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    ans += ext[a % 200];
    ext[a % 200]++;
  }
  cout << ans << endl;
}