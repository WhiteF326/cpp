#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    if(i % 2) a[i]--;
  }
  if(x >= accumulate(a.begin(), a.end(), 0)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}