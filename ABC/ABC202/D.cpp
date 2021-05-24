#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // 先に組み合わせを求めておく
  
  vector<vector<ll>> c(65, vector<ll>(65, 0));
  c[0][0] = 1;
  for(int i = 1; i < 61; i++){
    c[i][0] = 1;
    for(int j = 1; j < 61; j++){
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }

  ll a, b, k; cin >> a >> b >> k; k--;
  int fullLen = a + b;

  queue<string> anslist;
  for(int i = 0; i < fullLen; i++){
    // a+b C a
    ll s = c[a + b][a];
    // cout << s << endl;
    // sをa:bで分ける
    ll division = s * a / (a + b);
    //cout << division << endl;
    if(division <= k){
      // b
      anslist.push("b");
      b--;
      k -= division;
    }else{
      // a
      anslist.push("a");
      a--;
    }
  }
  while(!anslist.empty()){
    cout << anslist.front();
    anslist.pop();
  }cout << endl;
}