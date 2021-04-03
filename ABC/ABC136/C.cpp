//逆から
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<int> h(n); bool ans = true;
  for(int i = 0; i < n; i++){cin >> h[i];}
  for(int i = n - 2; i >= 0; i--){
    if(h[i] - h[i + 1] == 1){h[i]--;}
    else if(h[i] - h[i + 1] > 1){ans = false; break;}
  }
  cout << (ans ? "Yes" : "No") << endl;
}