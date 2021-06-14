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
  int a, b, w; cin >> a >> b >> w;
  w *= 1000;
  int mx = (int)floor(w / (double)a);
  int mn = (int)ceil(w / (double)b);
  if(mx < mn){
    cout << "UNSATISFIABLE" << endl;
  }else{
    cout << mn << " " << mx << endl;
  }
}