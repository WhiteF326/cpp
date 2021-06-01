#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int gcd(int i, int j){
  if(i % j){
    return gcd(j, i % j);
  }else return j;
}

int main(){
  int k, n; cin >> k >> n;
  priority_queue<int> q;
  int first; cin >> first;
  int back = first;
  for(int i = 1; i < n; i++){
    int a; cin >> a;
    q.push(a - back);
    back = a;
  }
  q.push(first + (k - back));
  q.pop();
  int ans = 0;
  while(!q.empty()){
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
}