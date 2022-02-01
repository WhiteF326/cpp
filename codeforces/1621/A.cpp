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
    int n, k; cin >> n >> k;
    int mx = n / 2 + n % 2;
    if(mx < k){
      cout << -1 << endl;
    }else{
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i == j && i % 2 == 0 && k){
            cout << "R";
            k--;
          }else{
            cout << ".";
          }
        }cout << endl;
      }
    }
  }
}