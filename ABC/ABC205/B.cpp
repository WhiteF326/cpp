#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[x]++;
  }
  for(int i = 0; i < n; i++){
    if(a[i + 1] != 1){cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
}