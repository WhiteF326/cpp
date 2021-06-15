#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  vector<int> pts(5, 0);
  for(int i = 0; i < 5; i++) cin >> pts[i];
  int k; cin >> k;
  bool ans = true;
  for(int i = 0; i < 4; i++){
    for(int j = i + 1; j < 5; j++){
      if(pts[j] - pts[i] > k) ans = false;
    }
  }
  cout << (ans ? "Yay!" : ":(") << endl;
}