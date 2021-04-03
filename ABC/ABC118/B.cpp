#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m; vector<int> a(m);
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){int d; cin >> d; a[d - 1]++;}
  }
  int ans = 0;
  for(int i = 0; i < m; i++){if(a[i] == n){ans++;}}
  cout << ans << endl;
}