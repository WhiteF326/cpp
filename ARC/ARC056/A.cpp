#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll a, b, k, l; cin >> a >> b >> k >> l;
  if(k < l){
    cout << min(b, k * a) << endl;
    return 0;
  }
  // k >= lならば、l個セットで買う方がかならず得
  ll ans = b * (k / l);
  if(k % l){
    // 余りを1個ずつ買うかセットで買うか
    if(a * (k % l) < b){
      ans += a * (k % l);
    }else ans += b;
  }
  cout << ans << endl;
}