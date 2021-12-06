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
  int n, k; cin >> n >> k;
  int cur = (n - 1) * (n - 2) / 2;

  if(k > cur){
    cout << -1 << endl;
    return 0;
  }

  queue<pair<int, int>> q;

  for(int i = 1; i < n; i++){
    q.push({0, i});
  }
  for(int i = 1; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(cur > k){
        q.push({i, j});
        cur--;
      }
    }
  }

  cout << q.size() << endl;
  while(!q.empty()){
    cout << q.front().first + 1 << " " << q.front().second + 1 << endl;
    q.pop();
  }
}