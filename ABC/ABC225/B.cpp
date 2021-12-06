#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  map<int, int> mc;
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    mc[a]++, mc[b]++;
  }
  for(int i = 1; i <= n; i++){
    if(mc[i] == n - 1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}