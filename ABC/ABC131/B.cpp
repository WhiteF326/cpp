#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int sign(int r){
  if(r > 0) return 1;
  else if(r < 0) return -1;
  else return 0;
}

int main(){
  int n, l; cin >> n >> l;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    d[i] = l + i;
  }
  int r = accumulate(d.begin(), d.end(), 0);

  map<int, bool> lis;
  for(int i = 0; i < n; i++){
    int esc = d[i];
    d[i] = 0;
    lis[accumulate(d.begin(), d.end(), 0)] = true;
    d[i] = esc;
  }

  for(int i = 0; i <= 10000; i++){
    if(lis[r + i]){
      cout << r + i << endl;
      return 0;
    }else if(lis[r - i]){
      cout << r - i << endl;
      return 0;
    }
  }
}