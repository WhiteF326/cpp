#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, h; cin >> n >> h;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int mx = *max_element(a.begin(), a.end());
  
  sort(b.begin(), b.end(), greater<int>());
  int v = n;
  for(int i = 0; i < n; i++){
    if(b[i] < mx){
      v = i;
      break;
    }
    h -= b[i];
    if(h <= 0){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << (int)(v + ceil((double)h / mx)) << endl;
}