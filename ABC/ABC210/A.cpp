#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  ll n, a, x, y; cin >> n >> a >> x >> y;
  if(n > a){
    cout << x * a + y * (n - a) << endl;
  }else{
    cout << n * x << endl;
  }
}