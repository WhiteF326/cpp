#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

vector<int> q(0);
int n;
map<int, int> apr;
set<int> ans;

int reppow(int x, int n){
  int ret = 1;
  while(n > 0){
    if(n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int dfs(int digit){
  if(q.size() > 8) return 0;
  apr[digit]++;
  q.emplace_back(digit);
  int res = 0;
  for(int i = 0; i < q.size(); i++){
    res += q[i] * reppow(10, i);
  }
  if(res <= n){
    if(apr[3] > 0 && apr[5] > 0 && apr[7] > 0){
      ans.insert(res);
    }
    dfs(3);
    dfs(5);
    dfs(7);
  }
  q.pop_back();
  apr[digit]--;
  return 0;
}

int main(){
  // dfs
  cin >> n;

  dfs(3);
  dfs(5);
  dfs(7);

  cout << ans.size() << endl;
}