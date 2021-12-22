#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  set<ll> s;
  
  int n; cin >> n;
  if(n == 3){
    cout << "6 10 15" << endl;
    return 0;
  }

  int cur = 6;
  while(cur <= 10000){
    s.insert(cur);
    cur += 6;
  }
  cur = 10;
  while(cur <= 10000){
    s.insert(cur);
    cur += 10;
  }
  cur = 15;
  while(cur <= 10000){
    s.insert(cur);
    cur += 15;
  }

  // cout << s.size() << endl;

  vector<int> ans;
  for(int v : s){
    ans.push_back(v);
    if(ans.size() == n) break;
  }

  for(int v : ans) cout << v << " ";
  cout << endl;
}