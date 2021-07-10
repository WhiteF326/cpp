#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  
  if(accumulate(a.begin(), a.end(), 0LL) < accumulate(b.begin(), b.end(), 0LL)){
    cout << -1 << endl;
  }else{
    
  }
}