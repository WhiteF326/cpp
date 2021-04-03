#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int n, m; cin >> n >> m; vector<int> v(n + m);
  for(int i = 0; i < n + m; i++) v[i] = (int)(i >= n);
  int ans = 0;
  for(int i = 0; i < n + m - 1; i++){
    for(int j = i + 1; j < n + m; j++){
      if(v[i] == v[j])ans++;
    }
  }
  cout << ans << endl;
}