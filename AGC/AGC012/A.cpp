#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<int> a(n * 3);
  for(int i = 0; i < n * 3; i++){cin >> a[i];}
  sort(a.begin(), a.end()); long long ans = 0;
  for(int i = 0; i < n; i++){ans += a[i * 2 + n];}
  cout << ans << endl;
}