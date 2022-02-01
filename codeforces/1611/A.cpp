#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    string s; cin >> s;
    int n = stoi(s);
    if(n % 2 == 0){
      cout << 0 << endl;
    }else if((s[0] - '0') % 2 == 0){
      cout << 1 << endl;
    }else{
      bool flg = false;
      for(int c : s){
        if((c - '0') % 2 == 0){
          flg = true;
          cout << 2 << endl;
          break;
        }
      }
      if(!flg){
        cout << -1 << endl;
      }
    }
  }
}