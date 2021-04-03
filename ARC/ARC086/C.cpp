#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    a[t]++;
  }
  if(a.size() <= k){cout << 0 << endl; return 0;}
  vector<int> al(0); int c = 0;
  for(auto itr = a.begin(); itr != a.end(); ++itr){
    al.push_back(itr->second);
  }
  sort(al.begin(), al.end()); int ans = 0;
  for(int i = 0; i < al.size() - k; i++){
    ans += al[i];
  }
  cout << ans;
}