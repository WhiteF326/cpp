#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int q; cin >> q;
  priority_queue<ll, vector<ll>, greater<ll>> xl;
  queue<ll> ans;
  ll res = 0;
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    if(t == 1){
      ll x; cin >> x;
      xl.push(x - res);
    }else if(t == 2){
      ll x; cin >> x;
      res += x;
    }else{
      ll x = xl.top();
      xl.pop();
      ans.push(x + res);
    }
  }
  while(!ans.empty()){
    cout << ans.front() << endl;
    ans.pop();
  }
}