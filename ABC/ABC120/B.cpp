#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int a, b, k; cin >> a >> b >> k;
  vector<int> anslist(0);
  for(int i = 1; i <= min(a, b); i++){
    if(a % i == 0 && b % i == 0) anslist.emplace_back(i);
  }
  reverse(anslist.begin(), anslist.end());
  cout << anslist[k - 1] << endl;
}