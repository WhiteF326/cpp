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
  int a, b; cin >> a >> b;
  map<int, int> div;
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    if(p <= a) div[0]++;
    else if(p <= b) div[1]++;
    else div[2]++;
  }
  cout << min(div[0], min(div[1], div[2])) << endl;
}