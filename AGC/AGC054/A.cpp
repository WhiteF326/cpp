#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  string s; cin >> s;

  if(s[0] != s[n - 1]){
    cout << 1 << endl;
  }else{
    // 先頭と末端を除いて隣り合う文字列がどちらもs[0]と異なる場所があるか
    for(int i = 1; i < n - 1; i++){
      if(s[i] != s[0] && s[i + 1] != s[0]){
        cout << 2 << endl;
        return 0;
      }
    }
    cout << -1 << endl;
  }
}