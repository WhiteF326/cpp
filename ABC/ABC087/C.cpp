#include <bits/stdc++.h>
using namespace std;

int arrc(vector<int> arr, int pt){
  int ans = 0;
  for(int i = pt; i < arr.size(); i++)ans += arr[i];
  return ans;
}

int main(){
  int n; cin >> n; int ans = 0;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++){
    int tans = 0;
    for(int j = 0; j <= i; j++) tans += a[j];
    for(int j = i; j < n; j++) tans += b[j];
    ans = max(ans, tans);
  }
  cout << ans << endl;
}