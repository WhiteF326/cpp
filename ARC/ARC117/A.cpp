#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int sum(int a){
  return a * (a + 1) / 2;
}

int main(){
  int a, b; cin >> a >> b;
  queue<int> ans;
  if(a == b){
    for(int i = 0; i < a; i++){
      ans.push(i + 1);
      ans.push(-(i + 1));
    }
  }else{
    for(int i = 0; i < max(a, b); i++){
      ans.push(i + 1);
    }
    for(int i = 0; i < min(a, b) - 1; i++){
      ans.push(-(i + 1));
    }
    ans.push(-(sum(max(a, b)) - sum(min(a, b) - 1)));
    if(b > a){
      for(int i = 0; i < a + b; i++){
        int x = ans.front(); ans.pop();
        ans.push(-x);
      }
    }
  }
  for(int i = 0; i < a + b - 1; i++){
    cout << ans.front() << " ";
    ans.pop();
  }cout << ans.front() << endl;
}