#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  vector<int> in(3); for(int i = 0; i < 3; i++) cin >> in[i];
  sort(in.begin(), in.end());
  if(in[0] == 5 && in[1] == 5 && in[2] == 7) cout << "YES";
  else cout << "NO";
  cout << endl;
}