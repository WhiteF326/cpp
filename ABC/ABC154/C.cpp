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
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[x]++;
  }
  for(auto itr = a.begin(); itr != a.end(); itr++){
    if(itr->second > 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}