#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(a);

  sort(a.begin(), a.end());
  int med = a[n / 2];

  for(int i = 0; i < n; i++){
    if(b[i] >= med){
      cout << a[n / 2 - 1] << endl;
    }else cout << med << endl;
  }
}