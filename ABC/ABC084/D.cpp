#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // まず1~100000について素数を導出する
  vector<int> isPrime(100000, true);
  isPrime[0] = false;
  int ptr = 1;
  while(true){
    int p = -1;
    for(int i = ptr; i < 318; i++){
      if(isPrime[i]){
        p = i + 1; break;
      }
    }
    if(p < 0) break;
    for(int i = p * 2; i <= 100000; i += p){
      //cout << i << endl;
      isPrime[i - 1] = false;
    }
    ptr++;
  }

  // 次に2017-like Numberを全て求め、累積和をとっておく
  vector<int> dep(100000, 0);
  for(int i = 3; i < 100000; i += 2){
    dep[i] = dep[i - 2] + (isPrime[i - 1] && isPrime[(i + 1) / 2 - 1] ? 1 : 0);
  }
  queue<int> anslist;
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    if(l == 1) anslist.push(dep[r]);
    else anslist.push(dep[r] - dep[l - 2]);
  }
  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}