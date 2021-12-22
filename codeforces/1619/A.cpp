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
  int t; cin >> t;
  query(t){
    string s; cin >> s;
    if(s.length() % 2){
      cout << "NO" << endl;
    }else{
      int n = s.length();
      int m = n / 2;
      if(s.substr(0, m) == s.substr(m, m)){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }
}