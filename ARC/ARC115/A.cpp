#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      a[i] += (s[j] == '1');
    }
  }
  ll odd = 0, even = 0;
  for(int i = 0; i < n; i++){
    if(a[i] % 2) odd++;
    else even++;
  }
  cout << odd * even << endl;
}