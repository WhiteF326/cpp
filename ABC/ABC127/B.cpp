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
  ll r, d, x;
  cin >> r >> d >> x;
  for(int i = 0; i < 10; i++){
    cout << r * x - d << endl;
    x = r * x - d;
  }
}