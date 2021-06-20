#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> alist(0);
  int res; cin >> res;
  int len = 1;
  for(int i = 1; i < n; i++){
    int a; cin >> a;
    if(res != a){
      alist.emplace_back(len);
      len = 1;
      res = a;
    }else len++;
  }
  alist.emplace_back(len);
  int ans = 0;
  for(int i = 0; i < alist.size(); i++){
    ans += alist[i] / 2;
  }
  cout << ans << endl;
}