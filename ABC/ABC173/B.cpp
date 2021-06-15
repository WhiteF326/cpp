#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<string> j = {"AC", "WA", "TLE", "RE"};
  map<string, int> p;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    p[s]++;
  }
  for(int i = 0; i < 4; i++){
    cout << j[i] << " x " << p[j[i]] << endl;
  }
}