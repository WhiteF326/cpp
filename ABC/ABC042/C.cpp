#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

vector<bool> u(10, true);
vector<int> c;
int res = 0;

void dfs(int p){
  if(p > 5) return;
  if(res != 0){
    c.emplace_back(res);
  }
  res *= 10;
  for(int i = 0; i < 10; i++){
    if(u[i]){
      res += i;
      dfs(p + 1);
      res -= i;
    }
  }
  res /= 10;
}

int main(){
  int n, k; cin >> n >> k;
  for(int i = 0; i < k; i++){
    int d; cin >> d;
    u[d] = false;
  }
  dfs(-1);
  sort(c.begin(), c.end());
  for(int i = 0; i < c.size(); i++){
    if(c[i] >= n){
      cout << c[i] << endl;
      return 0;
    }
  }
}