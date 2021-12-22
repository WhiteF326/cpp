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


int compare(string a, string b){
  if(a.length() > b.length()) return 1;
  else if(a.length() < b.length()) return -1;
  else{
    for(int i = 0; i < a.length(); i++){
      if(a[i] > b[i]) return 1;
      else if(a[i] < b[i]) return -1;
    }
    return 0;
  }
}
int main(){
  int t; cin >> t;
  query(t){
    ll a, b; cin >> a >> b;
    ll sa = a, sb = b;

    string ans = "";
    bool flg = false;
    while(a <= b){
      ll c = a % 10, d = b % 10;
      if(c <= d){
        a /= 10, b /= 10;
        ans = to_string(d - c) + ans;
      }else{
        a /= 10, b /= 100;
        ans = to_string(d - c + 10) + ans;
      }
      if(b == 0){
        flg = true;
        break;
      }
    }

    string res = "";
    ll save = stoll(ans);
    while(sa != 0 || save != 0){
      res = to_string((sa % 10) + (save % 10)) + res;
      sa /= 10, save /= 10;
    }

    if(flg && sb == stoll(res)){
      cout << stoll(ans) << endl;
    }else{
      cout << -1 << endl;
    }
  }
}