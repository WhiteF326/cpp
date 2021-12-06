#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int n = s.length();
  int k; cin >> k;

  // . の累積和
  vector<int> dsum(n + 1, 0);
  for(int i = 0; i < n; i++) dsum[i + 1] = s[i] == '.';
  for(int i = 1; i <= n; i++) dsum[i] += dsum[i - 1];

  int left = 0;
  int right = n;
  int mid = 0;

  while(right >= left){
    mid = left + (right - left) / 2;
    bool flg = false;
    for(int l = 0; l <= n - mid; l++){
      if(dsum[l + mid] - dsum[l] <= k){
        flg = true;
      }
    }
    
    if(flg){
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }

  int ans = 0;
  for(int i = max(0, mid - 2); i <= min(n, mid + 2); i++){
    bool flg = false;
    for(int j = 0; j <= n - i; j++){
      if(dsum[j + i] - dsum[j] <= k) flg = true;
    }
    if(flg) ans = max(ans, i);
  }

  cout << ans << endl;
}