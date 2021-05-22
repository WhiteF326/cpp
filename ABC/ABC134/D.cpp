#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<bool> box(n, false);
  for(int i = n; i >= 1; i--){
    bool flg = a[i - 1];
    for(int j = i * 2; j <= n; j += i){
      if(box[j - 1]) flg = !flg;
    }
    box[i - 1] = flg;
  }

  priority_queue<int, vector<int>, greater<int>> anslist;
  for(int i = 0; i < n; i++){
    if(box[i]) anslist.push(i + 1);
  }
  cout << anslist.size() << endl;
  if(anslist.size()){
    while(anslist.size() > 1){
      cout << anslist.top() << " ";
      anslist.pop();
    }cout << anslist.top() << endl;
  }
}