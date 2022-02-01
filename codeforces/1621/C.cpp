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
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<int> defined(n, 0);
    int ctr = 0;
    int ptr = 0, before = -1;
    while(true){
      cout << "? " << ptr + 1 << endl;
      fflush(stdout);
      int ans; cin >> ans;
      if(before == -1){
        before = ans - 1;
      }else if(before + 1 == ans || defined[ans - 1]){
        defined[before] = ans;
        ctr++;
        if(ctr == n){
          break;
        }
        // 次の場所を見る
        for(int i = 0; i < n; i++){
          if(!defined[i]){
            ptr = i;
            before = -1;
            break;
          }
        }
      }else{
        defined[before] = ans;
        before = ans - 1;
        ctr++;
        if(ctr == n){
          break;
        }
      }
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
      cout << defined[i] << " ";
    }cout << endl;
    fflush(stdout);
  }
}