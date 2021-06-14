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
  int a, b; cin >> a >> b;
  if(a <= 9 && b <= 9){
    cout << a * b << endl;
  }else cout << -1 << endl;
}