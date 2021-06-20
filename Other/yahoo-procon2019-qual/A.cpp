#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  n += n % 2;
  cout << (n / 2 >= k ? "YES" : "NO") << endl;
}