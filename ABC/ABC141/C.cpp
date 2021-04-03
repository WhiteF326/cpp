#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, q; scanf("%d%d%d", &n, &k, &q);
  vector<int> sc(n, 0);
  for(int i = 0; i < q; i++){
    int a; scanf("%d", &a);
    sc[a - 1]++;
  }
  for(int i = 0; i < n; i++){
    if(k - q + sc[i] >= 1){cout << "Yes" << endl;}else{cout << "No" << endl;}
  }
}