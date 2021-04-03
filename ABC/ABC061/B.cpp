#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<int> cl(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    cl[a - 1]++; cl[b - 1]++;
  }
  for(int i = 0; i < n; i++){
    cout << cl[i] << endl;
  }
}