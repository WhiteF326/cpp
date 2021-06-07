#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  // A1 = 0(未証明、なんで？)
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> b[i];
  vector<int> a(n);
  a[0] = 0;
  for(int i = 1; i < n; i++){
    a[i] = a[i - 1] ^ b[i - 1];
  }
  if((a[0] ^ a[n - 1]) != b[n - 1]){
    cout << -1 << endl;
  }else{
    for(int i = 0; i < n; i++){
      cout << a[i] << endl;
    }
  }
}
