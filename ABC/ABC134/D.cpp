#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // 降順から決められる？
  int n; cin >> n;
  vector<int> m(n);
  for(int i = 0; i < n; i++) cin >> m[i];

  vector<int> anslist(n, 0);
  for(int i = n; i > ceil(n / 2.0); i--){
    if(m[i - 1]) anslist[i - 1] = 1;
  }

  // -1になるパターンがない？
  for(int i = ceil(n / 2.0) - 1; i > 0; i--){
    int pt = i, r = 0;
    while(pt <= n){
      r += anslist[pt - 1];
      pt += i;
    }
    if(r % 2 != m[i - 1]) anslist[pt - 1] = 1;
  }

  vector<int> res(0);
  for(int i = 0; i < n; i++){
    if(anslist[i]) res.push_back(i + 1);
  }

  cout << res.size() << endl;
  if(res.size() == 0) return 0;
  for(auto itr = res.begin(); itr != res.end() - 1; itr++){
    cout << *itr << " ";
  }cout << res.back() << endl;
}