#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  priority_queue<int> q;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    q.push(x);
  }
  for(int i = 0; i < min(n, k); i++){
    q.pop();
  }
  ll ans = 0;
  while(!q.empty()){
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
}