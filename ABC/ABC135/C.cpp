#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<long long> a(n + 1), b(n);
  long long d = 0, e = 0;
  for(int i = 0; i < n + 1; i++){cin >> a[i]; d += a[i];}
  for(int i = 0; i < n; i++){cin >> b[i];}
  for(int i = n - 1; i >= 0; i--){
    if(a[i + 1] <= b[i]){
      //i + 1 を倒しきれる
      b[i] -= a[i + 1]; a[i + 1] = 0;
      //i
      a[i] -= min(a[i], b[i]);
    }else{
      //倒しきれない
      a[i + 1] -= b[i];
    }
  }
  for(int i = 0; i < n + 1; i++){e += a[i];}
  cout << (d - e) << endl;
}