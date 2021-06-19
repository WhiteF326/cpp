#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  vector<int> p(3);
  for(int i = 0; i < 3; i++) cin >> p[i];
  int d; cin >> d;
  // sort(p.begin(), p.end());

  if(abs(p[2] - p[0]) <= d || (abs(p[1] - p[0]) <= d && abs(p[2] - p[1]) <= d)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}