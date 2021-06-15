#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string n; cin >> n;
  for(int i = 0; i < 3; i++){
    if(n[i] == '1') cout << "9";
    else if(n[i] == '9') cout << "1";
  }
  cout << endl;
}