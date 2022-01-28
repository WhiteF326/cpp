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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    unordered_map<int, int> m;
    for(int i = 1; i <= n; i++){
      int x; cin >> x;
      m[x]++;
    }
    int c = 0;
    for(auto val : m){
      if(val.second >= 2){
        c++;
        for(auto val1: m){
          if(val1.first == (-val.first)){
            c--;
          }
        }
      }
    }

    int sum = m.size() + c;
    cout << sum << endl;
  }
}