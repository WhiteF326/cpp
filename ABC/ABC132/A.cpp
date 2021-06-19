#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  map<string, int> a;
  for(int i = 0; i < 4; i++){
    a[s.substr(i, 1)]++;
  }
  for(auto itr = a.begin(); itr != a.end(); itr++){
    if(itr->second != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}