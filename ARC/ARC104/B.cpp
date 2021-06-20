#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    map<char, int> app;
    app[s[i]]++;
    for(int j = i + 1; j < n; j++){
      app[s[j]]++;
      if(app['A'] == app['T'] && app['C'] == app['G']) ans++;
    }
  }
  cout << ans << endl;
}