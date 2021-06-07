#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int expow(int x, int n){
  int ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * x;
    x = x * x;
    n >>= 1;
  }
  return ans;
}

int main(){
  int n; cin >> n;
  stack<int> ans;
  // 絶対値が0に近づくかで判定
  for(int i = 0; i <= 30; i++){
    int d = expow(-2, i);
    // cout << d << endl;
    if(abs(n - d) <= abs(n)){
      ans.push(1);
      n -= d;
    }else{
      if(!ans.empty()) ans.push(0);
    }
  }
  while(!ans.empty()){
    cout << ans.top();
    ans.pop();
  }cout << endl;
}