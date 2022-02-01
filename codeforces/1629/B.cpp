#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int tt; cin >> tt;
  query(tt){
    int l, r, k; cin >> l >> r >> k;

    if(l == r){
      if(l == 1) cout << "NO" << endl;
      else cout << "YES" << endl;
    }else{
      if((r - l + 1) % 2){
        // 個数が奇数
        if(l % 2 == 0){
          if((r - l + 1) / 2 <= k){
            cout << "YES" << endl;
          }else{
            cout << "NO" << endl;
          }
        }else{
          if((r - l + 1) / 2 + 1 <= k){
            cout << "YES" << endl;
          }else{
            cout << "NO" << endl;
          }
        }
      }else{
        // 個数は偶数
        if((r - l + 1) / 2 <= k){
          cout << "YES" << endl;
        }else{
          cout << "NO" << endl;
        }
      }
    }
  }
}