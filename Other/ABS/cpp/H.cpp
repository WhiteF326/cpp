#include <bits/stdc++.h>
using namespace std;

int main(){
  int mc; cin >> mc;
  vector<int> msize(mc);
  for(int i = 0; i < mc; i++){
    cin >> msize[i];
  }
  sort(msize.begin(), msize.end(), greater<>());
  int rsize = msize[0];
  int ans = 1;
  for(int i = 1; i < mc; i++){
    if(rsize > msize[i]){
      rsize = msize[i];
      ans++;
    }
  }
  cout << ans << endl;
}