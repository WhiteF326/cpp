#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int k; cin >> k;
  sort(all(s));
  vector<string> anslist;
  do{
    anslist.push_back(s);
  }while(next_permutation(all(s)));
  cout << anslist[k - 1] << endl;
}