#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b){
  if(a % b){
    return gcd(b, (a % b));
  }else{
    return b;
  }
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

int main(){
  ll a, b; cin >> a >> b;
  cout << lcm(a, b) << endl;
}