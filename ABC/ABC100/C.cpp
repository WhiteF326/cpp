#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<int> s(n), a(n);
  int maxs = 0;
  for(int i = 0; i < n; i++){
    cin >> s[i]; maxs = max(maxs, s[i]);
  }
  for(int i = 0; i <= (int)log2(maxs + 1); i++){
    for(int j = 0; j < n; j++){
      if(s[j] % (int)pow(2, i) == 0 && s[j] >= pow(2, i)){a[j] = i;}
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) ans += a[i];
  cout << ans << endl;
}