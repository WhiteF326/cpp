#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<int> app(200001, false);
  int before_ans = 0;
  for(int i = 0; i < n; i++){
    int p; cin >> p;
    app[p] = true;
    for(int j = before_ans; j < 200001; j++){
      if(!app[j]){
        cout << j << endl;
        before_ans = j;
        break;
      }
    }
  }
}