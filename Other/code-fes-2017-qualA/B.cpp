#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  int k; cin >> k;

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(n * m - m * i - n * j + i * j * 2 == k){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}