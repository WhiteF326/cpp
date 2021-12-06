#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> res(n);
  for(int i = 0; i < n; i++) cin >> res[i];
  //偶数は左から 奇数は右から
  int vct = n % 2 ? 1 : -1;
  int ptr = n / 2, dist = 1;
  vector<int> poslist(n);
  for(int i = 0; i < n; i++){
    poslist[ptr] = i;
    ptr += dist * vct;
    dist++; vct *= -1;
  }
  vector<int> ans(n);
  for(int i = 0; i < n; i++) ans[i] = res[poslist[i]];
  for(int i = 0; i < n - 1; i++){
    cout << ans[i] << " ";
  }
  cout << ans[n - 1] << endl;
}