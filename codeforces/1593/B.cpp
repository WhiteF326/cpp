#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    string k; cin >> k;
    reverse(all(k));

    int n = k.length();
    int ans = n;
    // for 25, 75
    bool flg1 = false;
    for(int i = 0; i < n; i++){
      if(flg1 && (k[i] == '2' || k[i] == '7')){
        ans = min(ans, i - 1);
      }else if(!flg1 && k[i] == '5'){
        flg1 = true;
      }
    }

    // for 50, 00
    bool flg2 = false;
    for(int i = 0; i < n; i++){
      if(flg2 && (k[i] == '0' || k[i] == '5')){
        ans = min(ans, i - 1);
      }else if(!flg2 && k[i] == '0'){
        flg2 = true;
      }
    }

    cout << ans << endl;
  }
}