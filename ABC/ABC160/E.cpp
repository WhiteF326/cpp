#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int x, y; cin >> x >> y;
  int a, b, c; cin >> a >> b >> c;
  priority_queue<int> p, q, r;
  priority_queue<int> ans;
  for(int i = 0; i < a; i++){int x; cin >> x; p.push(x);}
  for(int i = 0; i < b; i++){int x; cin >> x; q.push(x);}
  for(int i = 0; i < c; i++){int x; cin >> x; ans.push(x);}
  
  for(int i = 0; i < x; i++){ans.push(p.top()); p.pop();}
  for(int i = 0; i < y; i++){ans.push(q.top()); q.pop();}

  ll res = 0;
  for(int i = 0; i < x + y; i++){
    res += ans.top();
    ans.pop();
  }
  cout << res << endl;
}
