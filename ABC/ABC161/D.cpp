#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int k; cin >> k;

  deque<ll> anslist;
  int ptr = 0;

  // bfsで無理矢理解く
  bool flg = false;
  for(int i = 1; i <= 10; i++){
    for(int j = 1; j <= 9; j++){
      if(anslist.size() > 100000){
        flg = true;
        break;
      }
      queue<ll> q;
      q.push(j);
      while(!q.empty()){
        ll x = q.front();
        q.pop();
        if(to_string(x).length() == i){
          anslist.push_back(x);
        }else{
          ll lastDigit = x % 10;
          for(int i = max(0LL, lastDigit - 1); i <= min(9LL, lastDigit + 1); i++){
            q.push(x * 10 + i);
          }
        }
      }
    }
    if(flg) break;
  }

  cout << anslist[k - 1] << endl;
}