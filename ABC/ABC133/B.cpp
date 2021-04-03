#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, d; cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for(int i = 0; i < n; i++){for(int j = 0; j < d; j++){cin >> x[i][j];}}
  int ans = 0; int tmp;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      tmp = 0;
      for(int k = 0; k < d; k++){tmp += (int)pow(abs(x[i][k] - x[j][k]), 2);}
      if(tmp == (int)pow((int)sqrt(tmp), 2)){ans++;}
    }
  }
  cout << ans << endl;
}