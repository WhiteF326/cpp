#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll modv = 1000000007;

int main(){
  int n; cin >> n;
  int m; cin >> m;
  vector<ll> sp(n + 5, 0);
  sp[0] = 1;
  vector<bool> b(n + 5, true);
  for(int i = 0; i < m; i++){
    int a; cin >> a;
    b[a] = false;
  }
  for(int i = 0; i < n; i++){
    if(b[i + 1]){
      sp[i + 1] = (sp[i + 1] + sp[i]) % modv;
    }
    if(b[i + 2]){
      sp[i + 2] = (sp[i + 2] + sp[i]) % modv;
    }
  }
  cout << sp[n] << endl;
}