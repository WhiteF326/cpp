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
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  for(int i = n - 1; i > 0; i--){
    if(h[i] < h[i - 1] - 1){
      cout << "No" << endl;
      return 0;
    }else if(h[i] < h[i - 1]){
      h[i - 1]--;
    }
  }
  cout << "Yes" << endl;
}