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
  int n; cin >> n;
  string s; cin >> s;
  string t = s.substr(0, 2);

  for(int i = 2; i < n; i++){
    t += s.substr(i, 1);
    if(t.length() < 3) continue;
    if(t.substr(t.length() - 3, 3) == "fox"){
      for(int j = 0; j < 3; j++){
        t.pop_back();
      }
    }
  }
  cout << t.length() << endl;

}