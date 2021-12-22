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
    int n; cin >> n;
    string ans = "";
    bool find = false;
    for(int i = 0; i < n - 2; i++){
      string s; cin >> s;
      if(ans.length()){
        if(*ans.rbegin() != s[0]){
          ans += s;
          find = true;
        }else{
          ans += s[1];
        }
      }else{
        ans = s;
      }
    }
    if(!find){
      ans += "a";
    }
    cout << ans << endl;
  }
}