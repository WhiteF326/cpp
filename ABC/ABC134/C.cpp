#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n); vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){scanf("%d", &a[i]); b[i] = a[i];}
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++){
    if(a[n - 1] == b[i]){cout << a[n - 2] << endl;}else{cout << a[n - 1] << endl;}
  }
}