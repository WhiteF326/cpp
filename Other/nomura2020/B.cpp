#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  string t; cin >> t;
  for(int i = 0; i < t.length(); i++){
    if(t[i] == '?') t[i] = 'D';
  }
  cout << t << endl;
}