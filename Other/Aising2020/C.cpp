#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> anslist(10001, 0);
  // x, y, zどれも高々100
  for(int x = 1; x <= 100; x++){
    for(int y = 1; y <= 100; y++){
      for(int z = 1; z <= 100; z++){
        if(x * x + y * y + z * z + x * y + y * z + z * x <= 10000){
          anslist[x * x + y * y + z * z + x * y + y * z + z * x]++;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++){
    cout << anslist[i] << endl;
  }
}