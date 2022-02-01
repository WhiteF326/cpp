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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int a, b, c; cin >> a >> b >> c;
    // change a?
    int ea = b - (c - b);
    if(ea >= a && ea % a == 0){
      cout << "YES" << endl;
      continue;
    }
    // b
    int eb = (c + a) / 2;
    if(eb >= b && eb % b == 0 && (c + a) % 2 == 0){
      cout << "YES" << endl;
      continue;
    }
    // c
    int ec = b + (b - a);
    if(ec >= c && ec % c == 0){
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}