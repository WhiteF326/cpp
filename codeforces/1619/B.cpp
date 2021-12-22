#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  vector<int> v;
  for(int i = 1; i * i <= 1000000000; i++){
    v.push_back(i * i);
  }
  for(int i = 1; i * i * i <= 1000000000; i++){
    v.push_back(i * i * i);
  }

  sort(all(v));
  v.erase(unique(all(v)), v.end());

  int t; cin >> t;
  query(t){
    int n; cin >> n;
    cout << upper_bound(all(v), n) - v.begin() << endl;
  }
}