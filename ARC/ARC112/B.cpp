#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  ll b, c; cin >> b >> c;

  if(b < 0) b = -b, c++;
  if(!b){
    cout << c << endl;
  }else if(c <= 2){
    cout << c + 1 << endl;
  }else if(c <= 2 * b){
    cout << 2 * c - 1 << endl;
  }else{
    cout << 4 * b - 1 + (c - 2 * b) << endl;
  }
}