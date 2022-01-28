#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ifstream ifs("in07.txt");
  
  vector<int> n(1000);
  aryin(n, 1000);

  map<int, int> m;
  for(int i : n) m[i]++;

  for(auto p : m){
    cout << p.first << " " << p.second << endl;
  }
}